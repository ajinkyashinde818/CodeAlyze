import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.numeric;

void main() {
  long a, b;
  readf (" %d %d", &a, &b);
  writeln ( (a / gcd (a, b)) * b);
}
