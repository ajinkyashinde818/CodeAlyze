import argparse
import json
from pathlib import Path

import joblib
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.svm import LinearSVC

from audit_dataset import LABEL_ALIASES, SUPPORTED_EXTENSIONS, infer_label


RANDOM_SEED = 42


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


def build_pipeline(model_name: str) -> Pipeline:
    vectorizer = TfidfVectorizer(
        analyzer="char_wb",
        ngram_range=(3, 5),
        lowercase=False,
        max_features=250000,
        min_df=2,
    )
    if model_name == "logreg":
        classifier = LogisticRegression(
            max_iter=2000,
            class_weight="balanced",
            random_state=RANDOM_SEED,
        )
    elif model_name == "linearsvc":
        classifier = LinearSVC(max_iter=5000, random_state=RANDOM_SEED)
    else:
        raise ValueError(f"Unsupported model: {model_name}")
    return Pipeline([("tfidf", vectorizer), ("classifier", classifier)])


def main():
    parser = argparse.ArgumentParser(description="Train a reproducible CodeAlyze baseline model.")
    parser.add_argument("--dataset", default="dataset")
    parser.add_argument("--out", default="backend/models/codealyze_model.pkl")
    parser.add_argument("--metrics-out", default="reports/training_metrics.json")
    parser.add_argument("--model", choices=["logreg", "linearsvc"], default="logreg")
    parser.add_argument("--test-size", type=float, default=0.2)
    args = parser.parse_args()

    dataset_root = Path(args.dataset)
    if not dataset_root.exists():
        raise SystemExit(f"Dataset root does not exist: {dataset_root}")

    texts, labels, languages, paths = load_dataset(dataset_root)
    if len(texts) < 20:
        raise SystemExit("Not enough labeled source files to train. Need at least 20.")
    if set(labels) != {"ai", "human"}:
        raise SystemExit(f"Both ai and human labels are required. Found labels: {sorted(set(labels))}")

    train_texts, test_texts, train_labels, test_labels, _, test_languages, _, test_paths = train_test_split(
        texts,
        labels,
        languages,
        paths,
        test_size=args.test_size,
        random_state=RANDOM_SEED,
        stratify=labels,
    )

    pipeline = build_pipeline(args.model)
    pipeline.fit(train_texts, train_labels)
    predictions = pipeline.predict(test_texts)

    metrics = {
        "model": args.model,
        "random_seed": RANDOM_SEED,
        "dataset_root": str(dataset_root),
        "train_samples": len(train_texts),
        "test_samples": len(test_texts),
        "accuracy": accuracy_score(test_labels, predictions),
        "classification_report": classification_report(test_labels, predictions, output_dict=True),
        "confusion_matrix_labels": ["ai", "human"],
        "confusion_matrix": confusion_matrix(test_labels, predictions, labels=["ai", "human"]).tolist(),
        "per_language_accuracy": {},
        "test_paths": test_paths,
    }
    for language in sorted(set(test_languages)):
        idx = [i for i, value in enumerate(test_languages) if value == language]
        metrics["per_language_accuracy"][language] = accuracy_score(
            [test_labels[i] for i in idx],
            [predictions[i] for i in idx],
        )

    artifact = {
        "pipeline": pipeline,
        "metadata": {
            "model_version": f"{args.model}-charwb-3-5-seed-{RANDOM_SEED}",
            "model_type": args.model,
            "feature_config": {
                "analyzer": "char_wb",
                "ngram_range": [3, 5],
                "lowercase": False,
                "max_features": 250000,
                "min_df": 2,
            },
            "dataset_root": str(dataset_root),
            "random_seed": RANDOM_SEED,
            "training_metrics_path": args.metrics_out,
        },
    }

    out_path = Path(args.out)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    joblib.dump(artifact, out_path)

    metrics_path = Path(args.metrics_out)
    metrics_path.parent.mkdir(parents=True, exist_ok=True)
    metrics_path.write_text(json.dumps(metrics, indent=2), encoding="utf-8")
    print(f"Saved model artifact to {out_path}")
    print(f"Saved metrics to {metrics_path}")


if __name__ == "__main__":
    main()
