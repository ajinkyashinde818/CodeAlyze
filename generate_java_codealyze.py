"""Generate a flat, stylistically varied 10,000-file Java CodeAlyze corpus."""
from pathlib import Path

ROOT = Path(__file__).parent / "dataset" / "ai" / "java"
REQUESTED = [
    ("basic",700),("operators",400),("decision",700),("loops",900),("patterns",500),("methods",700),
    ("arrays",700),("strings",700),("oop",1000),("constructors",400),("inheritance",500),("polymorphism",400),
    ("encapsulation",300),("abstraction",300),("interfaces",300),("packages",200),("exceptions",400),("files",300),
    ("collections",600),("generics",200),("threads",300),("jdbc",200),("recursion",200),("search",150),
    ("sort",250),("math",300),("dp",150),("greedy",100),("projects",350),
]


def allocation():
    total = sum(count for _, count in REQUESTED)
    values = [[topic, count * 10000 // total, (count * 10000) % total] for topic, count in REQUESTED]
    for item in sorted(values, key=lambda x: (-x[2], x[0]))[:10000 - sum(x[1] for x in values)]:
        item[1] += 1
    return [(topic, count) for topic, count, _ in values]


def program(topic, n):
    value, other, span = n % 89 + 3, n % 31 + 2, n % 7 + 3
    name = ("value", "number", "count", "result")[n % 4]
    if topic == "basic":
        return ["class Main {", "public static void main(String[] args) {", f"int {name} = {value};", f'System.out.println("value=" + {name});', "}", "}"]
    if topic == "operators":
        return ["class Main {", "public static void main(String[] args) {", f"int left = {value}, right = {other};", 'System.out.println((left + right) + " " + (left * right));', "}", "}"]
    if topic == "decision":
        if n % 2:
            return ["class Main {", "public static void main(String[] args) {", f"int score = {value};", 'if (score >= 70) System.out.println("pass");', 'else System.out.println("practice");', "}", "}"]
        return ["class Main {", "public static void main(String[] args) {", f"int choice = {value % 3};", "switch (choice) {", 'case 0: System.out.println("zero"); break;', 'case 1: System.out.println("one"); break;', 'default: System.out.println("other");', "}", "}", "}"]
    if topic in {"loops", "patterns"}:
        text = 'System.out.print("*");' if topic == "patterns" else 'System.out.print(column + " ");'
        return ["class Main {", "public static void main(String[] args) {", f"for (int row = 1; row <= {span}; row++) {{", "for (int column = 1; column <= row; column++) {", text, "}", "System.out.println();", "}", "}", "}"]
    if topic in {"methods", "recursion"}:
        return ["class Main {", "static long factorial(int number) {", "return number < 2 ? 1 : number * factorial(number - 1);", "}", "public static void main(String[] args) {", f"System.out.println(factorial({n % 11}));", "}", "}"]
    if topic == "arrays":
        return ["class Main {", "public static void main(String[] args) {", f"int[] data = {{ {value}, {other}, {span} }};", "int sum = 0;", "for (int item : data) sum += item;", "System.out.println(sum);", "}", "}"]
    if topic == "strings":
        return ["class Main {", "public static void main(String[] args) {", 'String text = "codealyze";', "System.out.println(text.length());", "}", "}"]
    if topic in {"oop", "constructors", "encapsulation"}:
        return ["class Counter {", "private final int value;", "Counter(int start) { this.value = start; }", "int getValue() { return value; }", "}", "class Main {", "public static void main(String[] args) {", f"Counter counter = new Counter({value});", "System.out.println(counter.getValue());", "}", "}"]
    if topic in {"inheritance", "polymorphism", "abstraction", "interfaces"}:
        return ["interface Printable { int getValue(); }", "class Item implements Printable {", "public int getValue() { return 42; }", "}", "class Main {", "public static void main(String[] args) {", "Printable item = new Item();", "System.out.println(item.getValue());", "}", "}"]
    if topic == "packages":
        return ["class Utility {", "static int twice(int value) { return value * 2; }", "}", "class Main {", "public static void main(String[] args) {", f"System.out.println(Utility.twice({value}));", "}", "}"]
    if topic == "exceptions":
        return ["class Main {", "public static void main(String[] args) {", "try {", f"if ({value} % 2 == 1) throw new IllegalArgumentException(\"odd\");", 'System.out.println("even");', "} catch (IllegalArgumentException error) {", "System.out.println(error.getMessage());", "}", "}", "}"]
    if topic == "files":
        return ["import java.io.*;", "class Main {", "public static void main(String[] args) throws IOException {", "File file = File.createTempFile(\"codealyze\", \".txt\");", f"try (PrintWriter writer = new PrintWriter(file)) {{ writer.println({value}); }}", "System.out.println(file.length() > 0);", "file.delete();", "}", "}"]
    if topic in {"collections", "generics", "sort"}:
        return ["import java.util.*;", "class Main {", "public static void main(String[] args) {", f"List<Integer> data = new ArrayList<>(Arrays.asList({value}, {other}, {span}));", "Collections.sort(data);", "System.out.println(data.get(0));", "}", "}"]
    if topic == "threads":
        return ["class Main {", "public static void main(String[] args) throws InterruptedException {", "Thread worker = new Thread(() -> System.out.println(\"running\"));", "worker.start();", "worker.join();", "}", "}"]
    if topic == "jdbc":
        return ["import java.sql.*;", "class Main {", "public static void main(String[] args) {", "try {", "Class.forName(\"java.lang.String\");", 'System.out.println("JDBC setup example");', "} catch (ClassNotFoundException error) {", "System.out.println(error.getMessage());", "}", "}", "}"]
    if topic == "search":
        return ["import java.util.*;", "class Main {", "public static void main(String[] args) {", f"int[] data = {{2, 4, 6, {value}}};", f"System.out.println(Arrays.binarySearch(data, {value}));", "}", "}"]
    if topic == "math":
        return ["class Main {", "public static void main(String[] args) {", f"int number = {value}, divisor = 2;", "boolean prime = number > 1;", "while (divisor * divisor <= number) {", "if (number % divisor == 0) prime = false;", "divisor++;", "}", "System.out.println(prime);", "}", "}"]
    if topic == "dp":
        return ["class Main {", "public static void main(String[] args) {", f"int terms = {n % 20 + 2}, previous = 0, current = 1;", "for (int step = 2; step <= terms; step++) {", "int next = previous + current; previous = current; current = next;", "}", "System.out.println(current);", "}", "}"]
    if topic == "greedy":
        return ["class Main {", "public static void main(String[] args) {", f"int capacity = {value}, weight = {other};", "System.out.println(weight <= capacity);", "}", "}"]
    return ["class Main {", "public static void main(String[] args) {", f"int balance = {value * 100};", f"balance += {other};", "System.out.println(balance);", "}", "}"]


def format_source(raw, style, comment):
    indent = ("    ", "  ", "\t", "    ", "  ")[style]
    output, depth = (["// Example application"] if comment else []), 0
    for line in raw:
        if line.startswith("}"): depth = max(0, depth - 1)
        output.append(indent * depth + line)
        if line.endswith("{"): depth += 1
    if style == 3: output = [line.replace(") {", ")\n{") for line in output]
    return "\n".join(output) + "\n"


def main():
    ROOT.mkdir(parents=True, exist_ok=True)
    number = 1
    for topic, count in allocation():
        for local in range(1, count + 1):
            content = format_source(program(topic, local), (number + local) % 5, number % 7 == 0)
            (ROOT / f"file_{number}.java").write_text(content, encoding="utf-8", newline="\n")
            number += 1
    assert number == 10001
    print("Created 10000 Java files.")


if __name__ == "__main__":
    main()
