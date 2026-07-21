import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;

void main() {
  int a, b, c, n;
  readf (" %d %d %d %d", &a, &b, &c, &n);
  long res;
  foreach (x; 0 .. (n / a) + 1) {
    int n0 = n - a * x;
    foreach (y; 0 .. (n0 / b) + 1) {
      int n1 = n0 - y * b;
      if (!(n1 % c)) ++res;
    }
  }
  writeln (res);
}
