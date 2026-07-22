import os
import sqlite3
import re
from datetime import datetime
from typing import Dict, List, Optional

DB_PATH = os.path.join(os.path.dirname(__file__), "analytics.db")

EXT_MAP = {
    ".c": "C", ".h": "C",
    ".cpp": "C++", ".cc": "C++", ".cxx": "C++", ".hpp": "C++",
    ".java": "Java",
    ".py": "Python",
}

SUPPORTED_EXTENSIONS = (".c", ".cpp", ".cc", ".cxx", ".h", ".hpp", ".java", ".py")


def detect_language(filename: str) -> str:
    _, ext = os.path.splitext(filename.lower())
    return EXT_MAP.get(ext, "Unknown")


def detect_language_from_code(code: str) -> str:
    patterns = {
        "Python": [r'def\s+\w+\s*\(', r'import\s+\w+', r'from\s+\w+\s+import', r'print\s*\('],
        "Java": [r'public\s+(class|static|void)', r'System\.out\.', r'import\s+java\.'],
        "C++": [r'#include\s*<[a-z]+>', r'std::', r'cout\s*<<', r'class\s+\w+\s*{'],
        "C": [r'#include\s*<stdio', r'#include\s*<stdlib', r'printf\s*\(', r'int\s+main\s*\('],
    }
    scores = {}
    for lang, pttns in patterns.items():
        score = sum(1 for p in pttns if re.search(p, code))
        if score > 0:
            scores[lang] = score
    if scores:
        return max(scores, key=scores.get)
    return "Unknown"


def is_valid_code(code: str) -> bool:
    return bool(code and code.strip())


# --- Analytics Database ---

def init_db():
    conn = sqlite3.connect(DB_PATH)
    c = conn.cursor()
    c.execute("""
        CREATE TABLE IF NOT EXISTS analyses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp TEXT NOT NULL,
            language TEXT NOT NULL,
            prediction TEXT NOT NULL,
            confidence REAL NOT NULL,
            code_length INTEGER NOT NULL
        )
    """)
    c.execute("""
        CREATE TABLE IF NOT EXISTS daily_stats (
            date TEXT PRIMARY KEY,
            total INTEGER DEFAULT 0,
            ai_count INTEGER DEFAULT 0,
            human_count INTEGER DEFAULT 0
        )
    """)
    conn.commit()
    conn.close()


def record_analysis(language: str, prediction: str, confidence: float, code_length: int):
    conn = sqlite3.connect(DB_PATH)
    c = conn.cursor()
    now = datetime.now()
    ts = now.isoformat()
    date_str = now.strftime("%Y-%m-%d")
    c.execute(
        "INSERT INTO analyses (timestamp, language, prediction, confidence, code_length) VALUES (?, ?, ?, ?, ?)",
        (ts, language, prediction, confidence, code_length),
    )
    c.execute(
        "INSERT INTO daily_stats (date, total, ai_count, human_count) VALUES (?, 1, ?, ?) "
        "ON CONFLICT(date) DO UPDATE SET total = total + 1, "
        "ai_count = ai_count + ?, human_count = human_count + ?",
        (date_str, 1 if prediction == "AI Generated" else 0, 1 if prediction == "Human Written" else 0,
         1 if prediction == "AI Generated" else 0, 1 if prediction == "Human Written" else 0),
    )
    conn.commit()
    conn.close()


def get_analytics() -> Dict:
    conn = sqlite3.connect(DB_PATH)
    c = conn.cursor()

    c.execute("SELECT COUNT(*) FROM analyses")
    total = c.fetchone()[0]

    c.execute("SELECT COUNT(*) FROM analyses WHERE prediction = 'AI Generated'")
    ai_count = c.fetchone()[0]

    c.execute("SELECT COUNT(*) FROM analyses WHERE prediction = 'Human Written'")
    human_count = c.fetchone()[0]

    ai_pct = round(ai_count / total * 100, 1) if total > 0 else 0
    human_pct = round(human_count / total * 100, 1) if total > 0 else 0

    c.execute("""
        SELECT language, COUNT(*) as cnt FROM analyses
        GROUP BY language ORDER BY cnt DESC
    """)
    lang_dist = {row[0]: row[1] for row in c.fetchall()}

    c.execute("""
        SELECT date, total, ai_count, human_count FROM daily_stats
        ORDER BY date DESC LIMIT 30
    """)
    daily = [{"date": row[0], "total": row[1], "ai": row[2], "human": row[3]} for row in c.fetchall()]

    c.execute("""
        SELECT CASE
            WHEN confidence >= 90 THEN '90-100%'
            WHEN confidence >= 80 THEN '80-90%'
            WHEN confidence >= 70 THEN '70-80%'
            WHEN confidence >= 60 THEN '60-70%'
            ELSE '50-60%'
        END as bucket, COUNT(*) as cnt
        FROM analyses GROUP BY bucket ORDER BY bucket
    """)
    conf_dist = {row[0]: row[1] for row in c.fetchall()}

    conn.close()

    return {
        "total_analyses": total,
        "ai_count": ai_count,
        "human_count": human_count,
        "ai_percentage": ai_pct,
        "human_percentage": human_pct,
        "language_distribution": lang_dist,
        "daily_stats": daily,
        "confidence_distribution": conf_dist,
    }

