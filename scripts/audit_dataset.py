import argparse
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path


SUPPORTED_EXTENSIONS = {
    ".c": "C",
    ".h": "C",
    ".cpp": "C++",
    ".cc": "C++",
    ".cxx": "C++",
    ".hpp": "C++",
    ".java": "Java",
    ".py": "Python",
}
LABEL_ALIASES = {
    "ai": "ai",
    "ai_generated": "ai",
    "generated": "ai",
    "machine": "ai",
    "human": "human",
    "human_written": "human",
    "real": "human",
}


def file_sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def normalize_code(text: str) -> str:
    return "\n".join(line.rstrip() for line in text.replace("\r\n", "\n").replace("\r", "\n").split("\n")).strip()


def infer_label(path: Path, root: Path) -> str:
    for part in path.relative_to(root).parts:
        key = part.lower().replace("-", "_").replace(" ", "_")
        if key in LABEL_ALIASES:
            return LABEL_ALIASES[key]
    return "unknown"


def infer_split(path: Path, root: Path) -> str:
    for part in path.relative_to(root).parts:
        key = part.lower()
        if key in {"train", "training"}:
            return "train"
        if key in {"test", "testing", "holdout", "validation", "val"}:
            return key
    return "unspecified"


def collect(root: Path, short_char_limit: int):
    records = []
    exact_hashes = defaultdict(list)
    normalized_hashes = defaultdict(list)
    errors = []

    for path in root.rglob("*"):
        if not path.is_file() or path.suffix.lower() not in SUPPORTED_EXTENSIONS:
            continue

        label = infer_label(path, root)
        language = SUPPORTED_EXTENSIONS[path.suffix.lower()]
        split = infer_split(path, root)
        try:
            raw = path.read_bytes()
            text = raw.decode("utf-8", errors="replace")
            exact = hashlib.sha256(raw).hexdigest()
            normalized = hashlib.sha256(normalize_code(text).encode("utf-8")).hexdigest()
        except Exception as exc:
            errors.append({"path": str(path), "error": str(exc)})
            continue

        rel = str(path.relative_to(root))
        record = {
            "path": rel,
            "label": label,
            "language": language,
            "split": split,
            "bytes": len(raw),
            "chars": len(text),
            "lines": len(text.splitlines()),
            "empty": not text.strip(),
            "short": len(text.strip()) < short_char_limit,
            "exact_sha256": exact,
            "normalized_sha256": normalized,
            "label_visible_in_path": label != "unknown",
        }
        records.append(record)
        exact_hashes[exact].append(record)
        normalized_hashes[normalized].append(record)

    return records, exact_hashes, normalized_hashes, errors


def duplicate_groups(hash_map):
    return [
        [{"path": item["path"], "label": item["label"], "language": item["language"], "split": item["split"]} for item in items]
        for items in hash_map.values()
        if len(items) > 1
    ]


def split_overlap(hash_map):
    overlaps = []
    for items in hash_map.values():
        splits = {item["split"] for item in items}
        if "train" in splits and ({"test", "testing", "holdout", "validation", "val"} & splits):
            overlaps.append(
                [{"path": item["path"], "label": item["label"], "split": item["split"]} for item in items]
            )
    return overlaps


def write_markdown(report_path: Path, root: Path, summary: dict):
    lines = [
        "# Dataset Audit Report",
        "",
        f"Dataset root: `{root}`",
        "",
        "## Summary",
        "",
        f"- Source files scanned: {summary['total_files']}",
        f"- Empty files: {summary['empty_files']}",
        f"- Short files: {summary['short_files']}",
        f"- Read errors: {len(summary['read_errors'])}",
        f"- Exact duplicate groups: {summary['exact_duplicate_group_count']}",
        f"- Normalized duplicate groups: {summary['normalized_duplicate_group_count']}",
        f"- Train/test normalized overlap groups: {summary['train_test_overlap_group_count']}",
        "",
        "## Counts By Label And Language",
        "",
        "| Label | Language | Files |",
        "|---|---:|---:|",
    ]
    for key, count in sorted(summary["counts_by_label_language"].items()):
        label, language = key.split("::", 1)
        lines.append(f"| {label} | {language} | {count} |")

    lines.extend([
        "",
        "## Notes",
        "",
        "- Labels are inferred from directory names. If the dataset uses metadata files, extend this script before relying on the audit.",
        "- Normalized duplicates ignore trailing whitespace and line-ending differences only; this is not a full near-duplicate detector.",
        "- No files are modified or deleted by this audit.",
        "",
    ])
    report_path.write_text("\n".join(lines), encoding="utf-8")


def main():
    parser = argparse.ArgumentParser(description="Audit CodeAlyze dataset quality and leakage risks.")
    parser.add_argument("--dataset", default="dataset", help="Dataset root directory.")
    parser.add_argument("--out-json", default="reports/dataset_audit.json")
    parser.add_argument("--out-md", default="reports/DATASET_AUDIT_REPORT.md")
    parser.add_argument("--short-char-limit", type=int, default=40)
    args = parser.parse_args()

    root = Path(args.dataset)
    out_json = Path(args.out_json)
    out_md = Path(args.out_md)
    out_json.parent.mkdir(parents=True, exist_ok=True)
    out_md.parent.mkdir(parents=True, exist_ok=True)

    if not root.exists():
        summary = {
            "dataset_root": str(root),
            "available": False,
            "error": "Dataset root does not exist.",
            "total_files": 0,
        }
        out_json.write_text(json.dumps(summary, indent=2), encoding="utf-8")
        out_md.write_text(
            "# Dataset Audit Report\n\nDataset root was not found. No dataset claims could be verified.\n",
            encoding="utf-8",
        )
        raise SystemExit("Dataset root does not exist; wrote unavailable-data report.")

    records, exact_hashes, normalized_hashes, errors = collect(root, args.short_char_limit)
    counts = Counter(f"{record['label']}::{record['language']}" for record in records)
    exact_duplicates = duplicate_groups(exact_hashes)
    normalized_duplicates = duplicate_groups(normalized_hashes)
    overlaps = split_overlap(normalized_hashes)

    summary = {
        "dataset_root": str(root),
        "available": True,
        "total_files": len(records),
        "counts_by_label_language": dict(counts),
        "counts_by_label": dict(Counter(record["label"] for record in records)),
        "counts_by_language": dict(Counter(record["language"] for record in records)),
        "counts_by_split": dict(Counter(record["split"] for record in records)),
        "empty_files": sum(1 for record in records if record["empty"]),
        "short_files": sum(1 for record in records if record["short"]),
        "unknown_label_files": sum(1 for record in records if record["label"] == "unknown"),
        "exact_duplicate_group_count": len(exact_duplicates),
        "normalized_duplicate_group_count": len(normalized_duplicates),
        "train_test_overlap_group_count": len(overlaps),
        "exact_duplicate_examples": exact_duplicates[:20],
        "normalized_duplicate_examples": normalized_duplicates[:20],
        "train_test_overlap_examples": overlaps[:20],
        "read_errors": errors,
    }
    out_json.write_text(json.dumps(summary, indent=2), encoding="utf-8")
    write_markdown(out_md, root, summary)
    print(f"Scanned {len(records)} files. Wrote {out_json} and {out_md}.")


if __name__ == "__main__":
    main()
