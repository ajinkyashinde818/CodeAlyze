import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;

void main() {
  int n, r;
  readf (" %d %d", &n, &r);
  writeln ( (n >= 10) ? r : r + (100 * (10 - n)));
}
