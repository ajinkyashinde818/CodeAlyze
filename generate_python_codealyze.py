"""Generate a flat, style-diverse 10,000-file Python CodeAlyze corpus."""
from pathlib import Path

ROOT = Path(__file__).parent / "dataset" / "ai" / "python"
REQUESTED = [
    ("basic",700),("operators",300),("decision",700),("loops",800),("functions",700),("lists",700),
    ("tuples",250),("dicts",500),("sets",300),("strings",700),("comprehensions",250),("modules",250),
    ("files",500),("exceptions",350),("oop",900),("iterators",250),("decorators",200),("functional",250),
    ("regex",250),("json_csv",250),("numpy",300),("pandas",300),("matplotlib",200),("search",150),
    ("sort",200),("recursion",200),("dp",150),("greedy",100),("projects",650),
]


def allocation():
    total = sum(count for _, count in REQUESTED)
    values = [[topic, count * 10000 // total, (count * 10000) % total] for topic, count in REQUESTED]
    for item in sorted(values, key=lambda x: (-x[2], x[0]))[:10000 - sum(x[1] for x in values)]: item[1] += 1
    return [(topic, count) for topic, count, _ in values]


def code(topic, n):
    value, other, span = n % 89 + 3, n % 31 + 2, n % 7 + 3
    name = ("value", "number", "count", "result")[n % 4]
    if topic == "basic": return [f"{name} = {value}", f"print(f'value={{ {name} }}')"]
    if topic == "operators": return [f"left, right = {value}, {other}", "print(left + right, left * right, left % right)"]
    if topic == "decision": return [f"score = {value}", "if score >= 70:", "print('pass')", "else:", "print('practice')"]
    if topic == "loops": return [f"for number in range(1, {span + 1}):", "print(number)"]
    if topic == "functions": return ["def square(number):", "return number * number", f"print(square({value}))"]
    if topic == "lists": return [f"data = [{value}, {other}, {span}]", "print(sum(data))"]
    if topic == "tuples": return [f"point = ({value}, {other})", "print(point[0], point[1])"]
    if topic == "dicts": return [f"record = {{'id': {value}, 'name': 'learner'}}", "print(record['id'])"]
    if topic == "sets": return [f"items = {{{value}, {other}, {value}}}", "print(len(items))"]
    if topic == "strings": return ["text = 'codealyze'", "print(text.upper(), len(text))"]
    if topic == "comprehensions": return [f"squares = [number * number for number in range({span})]", "print(squares)"]
    if topic == "modules": return ["from math import sqrt", f"print(sqrt({value}))"]
    if topic == "files": return ["from pathlib import Path", "path = Path('temporary_example.txt')", f"path.write_text('{value}')", "print(path.read_text())", "path.unlink()"]
    if topic == "exceptions": return ["try:", f"value = {value} // 0", "except ZeroDivisionError:", "print('cannot divide by zero')"]
    if topic == "oop": return ["class Counter:", "def __init__(self, start):", "self.value = start", "def increment(self):", "self.value += 1", f"counter = Counter({value})", "counter.increment()", "print(counter.value)"]
    if topic == "iterators": return ["def values(limit):", "for item in range(limit):", "yield item", f"print(list(values({span})))"]
    if topic == "decorators": return ["def announce(function):", "def wrapper(*args):", "print('calling')", "return function(*args)", "return wrapper", "@announce", "def greet(name):", "print(name)", "greet('CodeAlyze')"]
    if topic == "functional": return ["from functools import reduce", f"data = [{value}, {other}, {span}]", "print(reduce(lambda left, right: left + right, data))"]
    if topic == "regex": return ["import re", "match = re.search(r'\\d+', 'item 42')", "print(match.group())"]
    if topic == "json_csv": return ["import json", f"record = {{'id': {value}, 'active': True}}", "print(json.dumps(record, sort_keys=True))"]
    if topic == "numpy": return ["import numpy as np", f"data = np.array([{value}, {other}, {span}])", "print(data.mean())"]
    if topic == "pandas": return ["import pandas as pd", f"frame = pd.DataFrame({{'score': [{value}, {other}]}})", "print(frame['score'].sum())"]
    if topic == "matplotlib": return ["import matplotlib.pyplot as plt", f"plt.plot([0, 1], [0, {value}])", "plt.close()"]
    if topic == "search": return [f"data = [2, 4, 6, {value}]", f"print(data.index({value}))"]
    if topic == "sort": return [f"data = [{value}, {other}, {span}]", "print(sorted(data))"]
    if topic == "recursion": return ["def factorial(number):", "return 1 if number < 2 else number * factorial(number - 1)", f"print(factorial({n % 11}))"]
    if topic == "dp": return [f"terms, previous, current = {n % 20 + 2}, 0, 1", "for _ in range(2, terms + 1):", "previous, current = current, previous + current", "print(current)"]
    if topic == "greedy": return [f"capacity, weight = {value}, {other}", "print(weight <= capacity)"]
    return [f"balance = {value * 100}", f"balance += {other}", "print(f'balance={balance}')"]


def format_code(raw, style, comment):
    indent = ("    ", "  ", "\t", "    ", "  ")[style]
    output, depth = (["# Example program"] if comment else []), 0
    for line in raw:
        if not line.startswith((" ", "\t")) and depth and not line.endswith(":"):
            depth = 0
        output.append(indent * depth + line)
        if line.endswith(":"): depth += 1
    return "\n".join(output) + "\n"


def main():
    ROOT.mkdir(parents=True, exist_ok=True)
    number = 1
    for topic, count in allocation():
        for local in range(1, count + 1):
            content = format_code(code(topic, local), (number + local) % 5, number % 7 == 0)
            (ROOT / f"file_{number}.py").write_text(content, encoding="utf-8", newline="\n")
            number += 1
    assert number == 10001
    print("Created 10000 Python files.")


if __name__ == "__main__": main()
