import std.stdio, std.conv, std.string, std.algorithm, std.range;

void main() {
  auto N = readln.split[0].to!int;
  auto A = readln.split.to!(int[]);
  auto B = readln.split.to!(int[]);
  auto C = readln.split.to!(int[]);

  int result = 0;
  int before = -1;
  foreach(a; A) {
    result += B[a - 1];
    if (before != -1 && a - before == 1) {
      result += C[before - 1];
    }
    before = a;
  }
  result.writeln;
}
