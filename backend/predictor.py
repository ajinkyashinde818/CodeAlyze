import hashlib
import json
import os
import re
from dataclasses import dataclass
from typing import Dict, Optional

import joblib
import numpy as np
from sklearn.pipeline import Pipeline

MODEL_PATH = os.path.join(os.path.dirname(__file__), "models", "codealyze_model.pkl")
MODEL_VERSION = os.environ.get("CODEALYZE_MODEL_VERSION", "legacy-codealyze-model")

REPORTS_DIR = os.path.join(os.path.dirname(__file__), "..", "reports")
DATASET_AUDIT_PATH = os.path.join(REPORTS_DIR, "dataset_audit.json")
EVALUATION_METRICS_PATH = os.path.join(REPORTS_DIR, "evaluation_metrics.json")

_model_instance: Optional[object] = None
_model_metadata: Optional[Dict] = None

PATTERNS = {
    "repetitive_naming": {
        "pattern": r'\b(var|temp|val|item|data|res|result|arr|elem)\d*\b',
        "description": "repetitive generic naming",
        "ai_style": True,
    },
    "snake_case": {
        "pattern": r'\b[a-z0-9]+_[a-z0-9_]+\b',
        "description": "snake_case naming convention",
        "ai_style": False,
    },
    "camel_case": {
        "pattern": r'\b[a-z]+[A-Z][a-zA-Z0-9]*\b',
        "description": "camelCase naming convention",
        "ai_style": True,
    },
    "consistent_indentation": {
        "pattern": r'\n(?:    |\t)',
        "description": "consistent indentation",
        "ai_style": True,
    },
    "inline_comments": {
        "pattern": r'//[^\n]*|#[^\n]*',
        "description": "inline comments",
        "ai_style": False,
    },
    "doc_comments": {
        "pattern": r'/\*\*[^*]*\*+(?:[^/*][^*]*\*+)*/|""".*?"""',
        "description": "documentation comments",
        "ai_style": True,
    },
    "short_variable_names": {
        "pattern": r'\b[a-z]\b',
        "description": "short single-letter variables",
        "ai_style": False,
    },
    "type_annotations": {
        "pattern": r':\s*(int|str|float|bool|list|dict|tuple|void|char|double)\b',
        "description": "type annotations",
        "ai_style": True,
    },
    "consistent_braces": {
        "pattern": r'\{\s*\n',
        "description": "consistent brace placement",
        "ai_style": True,
    },
    "error_handling": {
        "pattern": r'\b(try|catch|except|raise|throw|finally)\b',
        "description": "error handling blocks",
        "ai_style": False,
    },
}


class ModelUnavailableError(RuntimeError):
    """Raised when inference cannot proceed with a valid model artifact."""


@dataclass(frozen=True)
class PredictionResult:
    label: str
    class_id: str
    confidence_score: float
    raw_margin: float
    model_version: str
    confidence_method: str
    warning: str


def _artifact_sha256(path: str) -> str:
    digest = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def _normalize_artifact(artifact: object) -> tuple[object, Dict]:
    if isinstance(artifact, dict) and "pipeline" in artifact:
        pipeline = artifact["pipeline"]
        metadata = dict(artifact.get("metadata", {}))
    else:
        pipeline = artifact
        metadata = {}

    if not hasattr(pipeline, "predict"):
        raise ModelUnavailableError("Model artifact does not expose predict().")
    if not hasattr(pipeline, "decision_function"):
        raise ModelUnavailableError("Model artifact does not expose decision_function().")

    metadata.setdefault("model_version", MODEL_VERSION)
    return pipeline, metadata


def get_model() -> object:
    global _model_instance, _model_metadata
    if _model_instance is None:
        model_path = MODEL_PATH
        if not os.path.exists(model_path):
            alt_path = os.path.join(os.path.dirname(__file__), "..", "models", "codealyze_model.pkl")
            if os.path.exists(alt_path):
                model_path = alt_path
            else:
                raise ModelUnavailableError(f"Model not found at {MODEL_PATH} or {alt_path}")

        try:
            artifact = joblib.load(model_path)
            _model_instance, _model_metadata = _normalize_artifact(artifact)
            _model_metadata.setdefault("artifact_path", os.path.abspath(model_path))
            _model_metadata.setdefault("artifact_sha256", _artifact_sha256(model_path))
        except ModelUnavailableError:
            raise
        except Exception as exc:
            raise ModelUnavailableError(f"Failed to load model artifact: {exc}") from exc
    return _model_instance


def reset_model_cache() -> None:
    global _model_instance, _model_metadata
    _model_instance = None
    _model_metadata = None


def model_status() -> Dict:
    try:
        model = get_model()
        metadata = _model_metadata or {}
        return {
            "available": True,
            "model_type": type(model).__name__,
            "model_version": metadata.get("model_version", MODEL_VERSION),
            "artifact_sha256": metadata.get("artifact_sha256"),
            "classes": list(getattr(model, "classes_", [])),
        }
    except Exception as exc:
        return {
            "available": False,
            "error": str(exc),
            "model_version": MODEL_VERSION,
        }


# Verified feature configuration for the checked-in artifact. If the artifact
# embeds its own "feature_config" metadata (as produced by scripts/train_model.py),
# that value is preferred; otherwise these verified defaults are reported.
DEFAULT_FEATURE_CONFIG = {
    "analyzer": "char_wb",
    "ngram_range": [3, 5],
    "lowercase": False,
    "max_features": 250000,
}

SUPPORTED_LANGUAGES = ["C", "C++", "Java", "Python"]

KNOWN_LIMITATIONS = [
    "Scores are uncalibrated display scores derived from the SVM margin, not calibrated probabilities.",
    "Training-data quality, duplicate rate, and leakage risk are unverified because the dataset is absent.",
    "Very short snippets, obfuscated code, and mixed-origin code can be unreliable.",
    "The model estimates surface patterns; it does not understand authorship intent.",
    "Code from languages outside the supported set falls outside the training distribution.",
]


def _read_json(path: str) -> Optional[Dict]:
    """Read a JSON report if it exists and parses. Never raises."""
    try:
        if not os.path.exists(path):
            return None
        with open(path, "r", encoding="utf-8") as handle:
            data = json.load(handle)
        return data if isinstance(data, dict) else None
    except (OSError, ValueError):
        return None


def dataset_status() -> Dict:
    """Report the verified dataset status from the audit artifact.

    No counts are invented. When the audit report is missing or records an
    unavailable dataset root, an honest pending status is returned instead.
    """
    audit = _read_json(DATASET_AUDIT_PATH)
    if not audit:
        return {
            "available": False,
            "status": "Dataset audit not run",
            "detail": (
                "No dataset audit artifact was found. Run "
                "python scripts/audit_dataset.py --dataset <dataset> to generate one."
            ),
        }

    if not audit.get("available"):
        return {
            "available": False,
            "status": "Dataset not present in this checkout",
            "detail": audit.get("error", "Dataset root does not exist."),
            "dataset_root": audit.get("dataset_root"),
        }

    return {
        "available": True,
        "status": "Dataset audited",
        "dataset_root": audit.get("dataset_root"),
        "total_files": audit.get("total_files", 0),
        "counts_by_label": audit.get("counts_by_label", {}),
        "counts_by_language": audit.get("counts_by_language", {}),
        "counts_by_split": audit.get("counts_by_split", {}),
        "empty_files": audit.get("empty_files", 0),
        "short_files": audit.get("short_files", 0),
        "unknown_label_files": audit.get("unknown_label_files", 0),
        "exact_duplicate_group_count": audit.get("exact_duplicate_group_count", 0),
        "normalized_duplicate_group_count": audit.get("normalized_duplicate_group_count", 0),
        "train_test_overlap_group_count": audit.get("train_test_overlap_group_count", 0),
    }


def evaluation_status() -> Dict:
    """Report holdout evaluation metrics only if a real artifact exists."""
    metrics = _read_json(EVALUATION_METRICS_PATH)
    if not metrics:
        return {
            "available": False,
            "status": "Evaluation pending dataset verification",
            "detail": (
                "No holdout evaluation artifact exists in this checkout, so no accuracy, "
                "precision, recall, F1, or confusion matrix is reported."
            ),
        }

    per_language = metrics.get("per_language") or {}
    report = metrics.get("classification_report") or {}
    return {
        "available": True,
        "status": "Holdout evaluation available",
        "dataset_root": metrics.get("dataset_root"),
        "model_path": metrics.get("model_path"),
        "samples": metrics.get("samples"),
        "accuracy": metrics.get("accuracy"),
        "macro_f1": (report.get("macro avg") or {}).get("f1-score"),
        "confusion_matrix": metrics.get("confusion_matrix"),
        "confusion_matrix_labels": metrics.get("confusion_matrix_labels"),
        "per_language": per_language,
    }


def _classifier_name(model: object) -> Optional[str]:
    """Best-effort name of the final estimator in a pipeline, without assumptions."""
    steps = getattr(model, "steps", None)
    if steps:
        return type(steps[-1][1]).__name__
    return type(model).__name__


def model_info() -> Dict:
    """Return verified, artifact-sourced model information for the UI.

    No metrics are fabricated. When the artifact lacks embedded metadata, only
    values that were verified during the audit are reported.
    """
    status = model_status()
    if not status.get("available"):
        return {
            "available": False,
            "model_version": MODEL_VERSION,
            "error": status.get("error", "Model unavailable"),
            "dataset": dataset_status(),
            "evaluation": evaluation_status(),
            "known_limitations": KNOWN_LIMITATIONS,
        }

    metadata = _model_metadata or {}
    model = get_model()
    return {
        "available": True,
        "model_version": metadata.get("model_version", MODEL_VERSION),
        "model_type": status.get("model_type"),
        "pipeline_type": type(model).__name__,
        "feature_extractor": "TfidfVectorizer",
        "classifier": _classifier_name(model),
        "feature_config": metadata.get("feature_config", DEFAULT_FEATURE_CONFIG),
        "classes": status.get("classes", []),
        "artifact_sha256": metadata.get("artifact_sha256"),
        "score_method": "sigmoid_absolute_linear_svm_margin_not_calibrated",
        "supported_languages": SUPPORTED_LANGUAGES,
        "dataset": dataset_status(),
        "evaluation": evaluation_status(),
        "known_limitations": KNOWN_LIMITATIONS,
    }


def predict(code: str) -> PredictionResult:
    model = get_model()
    prediction = model.predict([code])[0]
    decision_values = model.decision_function([code])[0]
    confidence = 1.0 / (1.0 + np.exp(-abs(float(decision_values))))
    confidence_pct = round(confidence * 100, 1)
    raw_score = round(float(decision_values), 4)
    class_id = str(prediction)
    label = "AI Generated" if class_id == "ai" else "Human Written"
    metadata = _model_metadata or {}
    return PredictionResult(
        label=label,
        class_id=class_id,
        confidence_score=confidence_pct,
        raw_margin=raw_score,
        model_version=metadata.get("model_version", MODEL_VERSION),
        confidence_method="sigmoid_absolute_linear_svm_margin_not_calibrated",
        warning="This score is derived from an uncalibrated SVM margin and should not be treated as a probability.",
    )


def analyze_features(code: str) -> Dict:
    detected = {}
    for feature_name, config in PATTERNS.items():
        matches = re.findall(config["pattern"], code, re.MULTILINE)
        if matches:
            detected[feature_name] = {
                "count": len(matches),
                "description": config["description"],
                "ai_style": config["ai_style"],
                "type": "heuristic",
            }
    return detected

