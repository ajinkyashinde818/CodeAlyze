#!/usr/bin/env python3
"""Extract a balanced, conservative human-C set from a CodeNet Parquet shard."""
from __future__ import annotations

import argparse
import csv
import hashlib
import re
import shutil
from pathlib import Path

import pandas as pd

ROOT = Path(__file__).resolve().parents[1]
STDIO = re.compile(r'#\s*include\s*[<\"]stdio\.h[>\"]')
CPP = re.compile(r'\b(?:using\s+namespace|std::|cin\s*>>|cout\s*<<|class\s+|template\s*<|new\s+|delete\s+|namespace\s+)')
COMMENT = re.compile(r'/\*.*?\*/|//[^\n]*', re.DOTALL)
TOKEN = re.compile(r'[A-Za-z_]\w*|\d+|==|!=|<=|>=|&&|\|\||\S')


def normalise(code: str) -> str:
    return ' '.join(TOKEN.findall(COMMENT.sub('', code)))


def valid_c(code: str) -> tuple[str, str] | None:
    code = code.strip()
    if len(code) < 100 or not STDIO.search(code) or CPP.search(code):
        return None
    body = normalise(code)
    if len(body) < 250 or 'main' not in body:
        return None
    return code + '\n', hashlib.sha256(body.encode('utf-8')).hexdigest()


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('parquet', type=Path, help='CodeNet Parquet shard')
    parser.add_argument('--output', type=Path, default=ROOT / 'dataset/human/c')
    parser.add_argument('--limit', type=int, default=10_000)
    parser.add_argument('--clean', action='store_true', help='remove prior .c files in the output folder')
    args = parser.parse_args()

    data = pd.read_parquet(args.parquet)
    required = {'Text', 'Source', 'Date', 'Token_count'}
    missing = required - set(data.columns)
    if missing:
        raise SystemExit(f'Missing required columns: {sorted(missing)}')
    args.output.mkdir(parents=True, exist_ok=True)
    if args.clean:
        for path in args.output.glob('*.c'):
            path.unlink()
    manifest = args.output.parent / 'c_manifest.csv'
    if args.clean and manifest.exists():
        manifest.unlink()

    seen: set[str] = set()
    rows: list[dict[str, str]] = []
    for source_index, item in data.iterrows():
        if len(rows) == args.limit:
            break
        if not isinstance(item.Text, str):
            continue
        result = valid_c(item.Text)
        if result is None:
            continue
        code, normalised_sha = result
        if normalised_sha in seen:
            continue
        seen.add(normalised_sha)
        name = f'file_{len(rows) + 1}.c'
        (args.output / name).write_text(code, encoding='utf-8', newline='\n')
        rows.append({'file': name, 'source_row': str(source_index), 'source': str(item.Source), 'date': str(item.Date), 'token_count': str(item.Token_count), 'file_sha256': hashlib.sha256(code.encode('utf-8')).hexdigest(), 'normalised_sha256': normalised_sha})
    if len(rows) != args.limit:
        raise SystemExit(f'Only {len(rows)} valid, unique C programs found.')
    with manifest.open('w', encoding='utf-8', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    print(f'Wrote {len(rows)} C programs to {args.output}')
    print(f'Wrote provenance manifest to {manifest}')


if __name__ == '__main__':
    main()
