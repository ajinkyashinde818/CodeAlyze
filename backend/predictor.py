import os
import re
from typing import Dict, List, Tuple, Optional

import joblib
import numpy as np
from sklearn.pipeline import Pipeline

MODEL_PATH = os.path.join(os.path.dirname(__file__), "models", "codealyze_model.pkl")

_model_instance: Optional[Pipeline] = None

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


def get_model() -> Pipeline:
    global _model_instance
    if _model_instance is None:
        if not os.path.exists(MODEL_PATH):
            alt_path = os.path.join(os.path.dirname(__file__), "..", "models", "codealyze_model.pkl")
            if os.path.exists(alt_path):
                _model_instance = joblib.load(alt_path)
            else:
                raise FileNotFoundError(f"Model not found at {MODEL_PATH} or {alt_path}")
        else:
            _model_instance = joblib.load(MODEL_PATH)
    return _model_instance


def predict(code: str) -> Tuple[str, float, float]:
    model = get_model()
    prediction = model.predict([code])[0]
    decision_values = model.decision_function([code])[0]
    confidence = 1.0 / (1.0 + np.exp(-abs(decision_values)))
    confidence_pct = round(confidence * 100, 1)
    raw_score = round(float(decision_values), 4)
    label = "AI Generated" if prediction == "ai" else "Human Written"
    return label, confidence_pct, raw_score


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

