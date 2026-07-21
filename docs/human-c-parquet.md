# Extracting the human C baseline

Run from the repository root:

```powershell
python collectors/extract_human_c_parquet.py dataset/human/train-00007-of-00009.parquet --clean
```

The Parquet shard has no language column and includes C++. The extractor consequently uses a conservative C heuristic: `stdio.h` is required; common C++ constructs are rejected; files must have sufficient code and a `main`; and hashes of comment-free tokens remove duplicates. It writes 10,000 files only to `dataset/human/c`, never to `dataset/ai/c`, plus `dataset/human/c_manifest.csv` for provenance.

For evaluation, split by `source_row` groups or problem metadata when available rather than randomly by file, to limit duplicate-problem leakage. The compiler is not installed in this workspace, so compilation validation is intentionally not claimed; run it separately in an environment with GCC or Clang if required.
