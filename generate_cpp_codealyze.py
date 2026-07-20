"""Generate a flat, style-diverse 10,000-file C++ CodeAlyze corpus."""
from pathlib import Path

ROOT = Path(__file__).parent / "dataset" / "ai" / "cpp"
REQUESTED = [
    ("basic",700),("operators",400),("decision",700),("loops",900),("patterns",500),
    ("functions",700),("arrays",700),("strings",600),("pointers",500),("structures",200),
    ("classes",900),("constructors",400),("inheritance",500),("polymorphism",400),
    ("operator_overload",250),("function_overload",200),("templates",300),("exceptions",200),
    ("files",300),("stl",700),("algorithms",300),("linked",150),("trees",100),("graphs",100),
    ("search",100),("sort",200),("dp",150),("greedy",100),("math",300),("projects",300),
]


def allocation():
    total = sum(count for _, count in REQUESTED)
    items = [[topic, count * 10000 // total, (count * 10000) % total] for topic, count in REQUESTED]
    for item in sorted(items, key=lambda x: (-x[2], x[0]))[:10000 - sum(x[1] for x in items)]:
        item[1] += 1
    return [(topic, count) for topic, count, _ in items]


def program(topic, n):
    value, other, span = n % 89 + 3, n % 31 + 2, n % 7 + 3
    if topic == "basic":
        return ["#include <iostream>", "int main() {", f"int value = {value};", 'std::cout << "value=" << value << \'\\n\';', "}"]
    if topic == "operators":
        return ["#include <iostream>", "int main() {", f"int left = {value}, right = {other};", "std::cout << left + right << ' ' << left * right << '\\n';", "}"]
    if topic == "decision":
        return ["#include <iostream>", "int main() {", f"int score = {value};", 'if (score >= 70) std::cout << "pass\\n";', 'else std::cout << "practice\\n";', "}"]
    if topic in {"loops", "patterns"}:
        item = "'*'" if topic == "patterns" else "column"
        return ["#include <iostream>", "int main() {", f"for (int row = 1; row <= {span}; ++row) {{", "for (int column = 1; column <= row; ++column) {", f"std::cout << {item} << ' ';", "}", "std::cout << '\\n';", "}", "}"]
    if topic in {"functions", "recursion"}:
        return ["#include <iostream>", "int square(int number) {", "return number * number;", "}", "int main() {", f"std::cout << square({value}) << '\\n';", "}"]
    if topic == "arrays":
        return ["#include <iostream>", "int main() {", f"int data[] = {{ {value}, {other}, {span} }};", "int sum = 0;", "for (int item : data) sum += item;", "std::cout << sum << '\\n';", "}"]
    if topic == "strings":
        return ["#include <string>", "#include <iostream>", "int main() {", 'std::string text = "codealyze";', "std::cout << text.size() << '\\n';", "}"]
    if topic in {"pointers", "structures"}:
        if topic == "pointers":
            return ["#include <iostream>", "void increment(int& number) {", "++number;", "}", "int main() {", f"int value = {value};", "increment(value);", "std::cout << value << '\\n';", "}"]
        return ["#include <iostream>", "struct Record { int id; double mark; };", "int main() {", f"Record item{{{value}, {other}.5}};", "std::cout << item.id << ' ' << item.mark << '\\n';", "}"]
    if topic in {"classes", "constructors", "inheritance", "polymorphism"}:
        if topic == "inheritance":
            return ["#include <iostream>", "class Base { public: virtual int value() const { return 1; } };", f"class Derived : public Base {{ public: int value() const override {{ return {value}; }} }};", "int main() {", "Derived item; std::cout << item.value() << '\\n';", "}"]
        return ["#include <iostream>", "class Counter {", "int value;", "public:", f"Counter(int start) : value(start) {{}}", "int get() const { return value; }", "};", "int main() {", f"Counter item({value});", "std::cout << item.get() << '\\n';", "}"]
    if topic == "operator_overload":
        return ["#include <iostream>", "struct Number {", "int value;", "Number operator+(Number other) const { return {value + other.value}; }", "};", "int main() {", f"Number a{{{value}}}, b{{{other}}};", "std::cout << (a + b).value << '\\n';", "}"]
    if topic == "function_overload":
        return ["#include <iostream>", "int area(int side) { return side * side; }", "double area(double radius) { return 3.14 * radius * radius; }", "int main() {", f"std::cout << area({value}) << '\\n';", "}"]
    if topic == "templates":
        return ["#include <iostream>", "template <class T> T maximum(T left, T right) { return left > right ? left : right; }", "int main() {", f"std::cout << maximum({value}, {other}) << '\\n';", "}"]
    if topic == "exceptions":
        return ["#include <iostream>", "#include <stdexcept>", "int main() {", "try {", f"if ({value} % 2) throw std::runtime_error(\"odd\");", 'std::cout << "even\\n";', "} catch (const std::exception& error) {", "std::cout << error.what() << '\\n';", "}", "}"]
    if topic == "files":
        return ["#include <sstream>", "#include <iostream>", "int main() {", "std::stringstream stream;", f"stream << {value};", "int result = 0; stream >> result;", "std::cout << result << '\\n';", "}"]
    if topic in {"stl", "algorithms", "sort"}:
        return ["#include <algorithm>", "#include <vector>", "#include <iostream>", "int main() {", f"std::vector<int> data{{{value}, {other}, {span}}};", "std::sort(data.begin(), data.end());", "std::cout << data.front() << '\\n';", "}"]
    if topic in {"linked", "trees"}:
        return ["#include <memory>", "#include <iostream>", "struct Node { int value; std::unique_ptr<Node> next; };", "int main() {", f"auto head = std::make_unique<Node>(Node{{{value}, nullptr}});", "std::cout << head->value << '\\n';", "}"]
    if topic == "graphs":
        return ["#include <array>", "#include <iostream>", "int main() {", "std::array<std::array<int, 3>, 3> graph{};", "graph[0][1] = graph[1][0] = 1;", "std::cout << graph[0][1] << '\\n';", "}"]
    if topic == "search":
        return ["#include <algorithm>", "#include <vector>", "#include <iostream>", "int main() {", f"std::vector<int> data{{2, 4, 6, {value}}};", f"std::cout << std::binary_search(data.begin(), data.end(), {value}) << '\\n';", "}"]
    if topic == "dp":
        return ["#include <iostream>", "int main() {", f"int terms = {n % 20 + 2}, previous = 0, current = 1;", "for (int step = 2; step <= terms; ++step) {", "int next = previous + current; previous = current; current = next;", "}", "std::cout << current << '\\n';", "}"]
    if topic == "greedy":
        return ["#include <iostream>", "int main() {", f"int capacity = {value}, weight = {other};", "std::cout << (weight <= capacity) << '\\n';", "}"]
    if topic == "math":
        return ["#include <iostream>", "int main() {", f"int number = {value}, divisor = 2;", "bool prime = number > 1;", "while (divisor * divisor <= number) {", "if (number % divisor == 0) prime = false;", "++divisor;", "}", "std::cout << prime << '\\n';", "}"]
    return ["#include <iostream>", "int main() {", f"int balance = {value * 100};", f"balance += {other};", "std::cout << balance << '\\n';", "}"]


def format_source(raw, style, comment):
    indent = ("    ", "  ", "\t", "    ", "  ")[style]
    output, depth = (["/* Standalone example. */"] if comment else []), 0
    for line in raw:
        if line.startswith("}"): depth = max(0, depth - 1)
        output.append(indent * depth + line)
        if line.endswith("{"): depth += 1
    if style == 3: output = [line.replace(") {", ")\n{") for line in output]
    if style == 4:
        insert_at = 1 if output and output[0].startswith("/*") else 0
        while insert_at < len(output) and output[insert_at].startswith("#include"):
            insert_at += 1
        output.insert(insert_at, "using namespace std;")
        output = [line.replace("std::", "") for line in output]
    return "\n".join(output) + "\n"


def main():
    ROOT.mkdir(parents=True, exist_ok=True)
    number = 1
    for topic, count in allocation():
        for local in range(1, count + 1):
            code = format_source(program(topic, local), (number + local) % 5, number % 7 == 0)
            (ROOT / f"file_{number}.cpp").write_text(code, encoding="utf-8", newline="\n")
            number += 1
    assert number == 10001
    print("Created 10000 C++ files.")


if __name__ == "__main__":
    main()
