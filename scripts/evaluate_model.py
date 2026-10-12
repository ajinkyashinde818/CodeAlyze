import argparse
import json
from pathlib import Path

import joblib
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

from audit_dataset import SUPPORTED_EXTENSIONS, infer_label


def load_dataset(root: Path):
    texts = []
    labels = []
    languages = []
    paths = []
    for path in root.rglob("*"):
        if not path.is_file() or path.suffix.lower() not in SUPPORTED_EXTENSIONS:
            continue
        label = infer_label(path, root)
        if label not in {"ai", "human"}:
            continue
        texts.append(path.read_text(encoding="utf-8", errors="replace"))
        labels.append(label)
        languages.append(SUPPORTED_EXTENSIONS[path.suffix.lower()])
        paths.append(str(path.relative_to(root)))
    return texts, labels, languages, paths


def load_pipeline(path: Path):
    artifact = joblib.load(path)
    if isinstance(artifact, dict) and "pipeline" in artifact:
        return artifact["pipeline"], artifact.get("metadata", {})
    return artifact, {"model_version": "legacy-codealyze-model"}


def main():
    parser = argparse.ArgumentParser(description="Evaluate a CodeAlyze model on a labeled holdout dataset.")
    parser.add_argument("--dataset", required=True, help="Labeled holdout dataset root.")
    parser.add_argument("--model", default="backend/models/codealyze_model.pkl")
    parser.add_argument("--out", default="reports/evaluation_metrics.json")
    args = parser.parse_args()

    dataset_root = Path(args.dataset)
    model_path = Path(args.model)
    if not dataset_root.exists():
        raise SystemExit(f"Dataset root does not exist: {dataset_root}")
    if not model_path.exists():
        raise SystemExit(f"Model artifact does not exist: {model_path}")

    texts, labels, languages, paths = load_dataset(dataset_root)
    if not texts:
        raise SystemExit("No labeled source files found for evaluation.")

    pipeline, metadata = load_pipeline(model_path)
    predictions = pipeline.predict(texts)

    metrics = {
        "model_path": str(model_path),
        "model_metadata": metadata,
        "dataset_root": str(dataset_root),
        "samples": len(texts),
        "accuracy": accuracy_score(labels, predictions),
        "classification_report": classification_report(labels, predictions, output_dict=True),
        "confusion_matrix_labels": ["ai", "human"],
        "confusion_matrix": confusion_matrix(labels, predictions, labels=["ai", "human"]).tolist(),
        "per_language": {},
        "false_positives": [],
        "false_negatives": [],
    }

    for language in sorted(set(languages)):
        idx = [i for i, value in enumerate(languages) if value == language]
        metrics["per_language"][language] = {
            "samples": len(idx),
            "accuracy": accuracy_score([labels[i] for i in idx], [predictions[i] for i in idx]),
        }

    for path, truth, pred, language in zip(paths, labels, predictions, languages):
        if truth == pred:
            continue
        item = {"path": path, "truth": truth, "prediction": str(pred), "language": language}
        if truth == "human" and pred == "ai":
            metrics["false_positives"].append(item)
        elif truth == "ai" and pred == "human":
            metrics["false_negatives"].append(item)

    out_path = Path(args.out)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(json.dumps(metrics, indent=2), encoding="utf-8")
    print(f"Evaluated {len(texts)} samples. Wrote {out_path}.")


if __name__ == "__main__":
    main()
