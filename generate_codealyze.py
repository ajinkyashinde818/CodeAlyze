"""Build a flat, style-diverse CodeAlyze C corpus without generator markers."""
from pathlib import Path

ROOT = Path(__file__).parent / "dataset" / "ai" / "c"
TOPICS = [
    ("basic",721),("operators",450),("decision",721),("loops",901),("patterns",541),
    ("functions",721),("arrays",811),("strings",721),("pointers",631),("records",360),
    ("union",180),("files",450),("memory",360),("linked",270),("stack",135),
    ("queue",135),("tree",135),("graph",90),("search",135),("sort",225),
    ("bits",135),("math",450),("recursion",225),("dp",135),("greedy",90),("project",272),
]


def lines(topic, number):
    value, other, span = number % 83 + 3, number % 29 + 2, number % 7 + 3
    variable = ("value", "number", "count", "result")[number % 4]
    if topic == "basic":
        return ["#include <stdio.h>", "int main(void) {", f"int {variable} = {value};", f'printf("%d %c\\n", {variable}, \'A\' + {variable} % 26);', "return 0;", "}"]
    if topic == "operators":
        return ["#include <stdio.h>", "int main(void) {", f"int left = {value}, right = {other};", 'printf("%d %d %d\\n", left + right, left * right, left % right);', "return 0;", "}"]
    if topic == "decision":
        if number % 2:
            return ["#include <stdio.h>", "int main(void) {", f"int score = {value};", 'if (score >= 75) puts("pass");', 'else puts("practice");', "return 0;", "}"]
        return ["#include <stdio.h>", "int main(void) {", f"int choice = {value % 3};", "switch (choice) {", 'case 0: puts("zero"); break;', 'case 1: puts("one"); break;', 'default: puts("other");', "}", "return 0;", "}"]
    if topic in {"loops", "patterns"}:
        statement = "putchar('*');" if topic == "patterns" else 'printf("%d ", column);'
        return ["#include <stdio.h>", "int main(void) {", f"for (int row = 1; row <= {span}; ++row) {{", "for (int column = 1; column <= row; ++column) {", statement, "}", "putchar('\\n');", "}", "return 0;", "}"]
    if topic in {"functions", "recursion"}:
        return ["#include <stdio.h>", "long long factorial(int n) {", "return n < 2 ? 1 : n * factorial(n - 1);", "}", "int main(void) {", f'printf("%lld\\n", factorial({number % 11}));', "return 0;", "}"]
    if topic == "arrays":
        return ["#include <stdio.h>", "int main(void) {", f"int data[] = {{ {value}, {other}, {span}, {value + other} }};", "int sum = 0;", "for (int index = 0; index < 4; ++index) {", "sum += data[index];", "}", 'printf("%d\\n", sum);', "return 0;", "}"]
    if topic == "strings":
        return ["#include <string.h>", "#include <stdio.h>", "int main(void) {", 'char text[] = "codealyze";', 'printf("%zu\\n", strlen(text));', "return 0;", "}"]
    if topic == "pointers":
        return ["#include <stdio.h>", "void add_one(int *item) {", "++*item;", "}", "int main(void) {", f"int {variable} = {value};", f"add_one(&{variable});", f'printf("%d\\n", {variable});', "return 0;", "}"]
    if topic in {"records", "union"}:
        if topic == "union":
            return ["#include <stdio.h>", "typedef union { int code; char letter; } Token;", "int main(void) {", f"Token token; token.code = {value};", 'printf("%d\\n", token.code);', "return 0;", "}"]
        return ["#include <stdio.h>", "typedef struct { int id; float mark; } Record;", "int main(void) {", f"Record item = {{ {value}, {other}.5f }};", 'printf("%d %.1f\\n", item.id, item.mark);', "return 0;", "}"]
    if topic == "files":
        return ["#include <stdio.h>", "int main(void) {", "FILE *stream = tmpfile();", "if (stream == NULL) return 1;", f'fprintf(stream, "%d\\n", {value});', "rewind(stream);", "int read_value = 0; fscanf(stream, \"%d\", &read_value);", 'printf("%d\\n", read_value);', "fclose(stream);", "return 0;", "}"]
    if topic == "memory":
        return ["#include <stdlib.h>", "#include <stdio.h>", "int main(void) {", f"int *items = calloc({span}, sizeof *items);", "if (items == NULL) return 1;", f"items[0] = {value};", 'printf("%d\\n", items[0]);', "free(items);", "return 0;", "}"]
    if topic in {"linked", "stack", "queue", "tree"}:
        link = {"linked":"next", "stack":"next", "queue":"next", "tree":"left"}[topic]
        return ["#include <stdio.h>", f"typedef struct Node {{ int data; struct Node *{link}; }} Node;", "int main(void) {", f"Node second = {{ {other}, NULL }};", f"Node first = {{ {value}, &second }};", f'printf("%d\\n", first.{link}->data);', "return 0;", "}"]
    if topic == "graph":
        return ["#include <stdio.h>", "int main(void) {", "int graph[3][3] = {{0}};", "graph[0][1] = graph[1][0] = 1;", 'printf("%d\\n", graph[0][1]);', "return 0;", "}"]
    if topic == "search":
        return ["#include <stdio.h>", "int main(void) {", f"int data[] = {{ 2, 4, 6, 8, {value} }}, found = -1;", "for (int index = 0; index < 5; ++index) {", f"if (data[index] == {value}) {{ found = index; break; }}", "}", 'printf("%d\\n", found);', "return 0;", "}"]
    if topic == "sort":
        return ["#include <stdio.h>", "int main(void) {", f"int data[] = {{ {value}, {other}, {span} }};", "for (int pass = 0; pass < 2; ++pass) {", "for (int index = 0; index < 2 - pass; ++index) {", "if (data[index] > data[index + 1]) { int temp = data[index]; data[index] = data[index + 1]; data[index + 1] = temp; }", "}", "}", 'printf("%d\\n", data[0]);', "return 0;", "}"]
    if topic == "bits":
        return ["#include <stdio.h>", "int main(void) {", f"unsigned number = {value}u;", 'printf("%u %u\\n", number & 1u, (number >> 1) & 1u);', "return 0;", "}"]
    if topic == "math":
        return ["#include <stdio.h>", "int main(void) {", f"int number = {value}, divisor = 2, prime = number > 1;", "while (divisor * divisor <= number) {", "if (number % divisor == 0) prime = 0;", "++divisor;", "}", 'printf("%d\\n", prime);', "return 0;", "}"]
    if topic == "dp":
        return ["#include <stdio.h>", "int main(void) {", f"int terms = {number % 20 + 2}, previous = 0, current = 1;", "for (int step = 2; step <= terms; ++step) {", "int next = previous + current; previous = current; current = next;", "}", 'printf("%d\\n", current);', "return 0;", "}"]
    if topic == "greedy":
        return ["#include <stdio.h>", "int main(void) {", f"int capacity = {value}, weight = {other};", 'printf("%d\\n", weight <= capacity);', "return 0;", "}"]
    return ["#include <stdio.h>", "int main(void) {", f"int balance = {value * 100};", f"balance += {other};", 'printf("%d\\n", balance);', "return 0;", "}"]


def format_source(source_lines, style, include_comment):
    indent = ("    ", "  ", "\t", "    ", "  ")[style]
    depth, output = 0, []
    if include_comment:
        output.append("/* Example program. */")
    for line in source_lines:
        if line.startswith("}"):
            depth = max(0, depth - 1)
        output.append(indent * depth + line)
        if line.endswith("{"):
            depth += 1
    if style == 3:
        output = [line.replace(") {", ")\n{") for line in output]
    return "\n".join(output) + "\n"


def main():
    number = 1
    for topic, count in TOPICS:
        for local in range(1, count + 1):
            content = format_source(lines(topic, local), (number + local) % 5, number % 7 == 0)
            (ROOT / f"file_{number}.c").write_text(content, encoding="utf-8", newline="\n")
            number += 1
    assert number == 10001
    print("Regenerated 10000 C files.")


if __name__ == "__main__":
    main()
