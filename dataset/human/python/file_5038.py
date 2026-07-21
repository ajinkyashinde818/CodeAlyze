import std.stdio;
import std.conv;
import std.string;
import std.typecons;
import std.algorithm;
import std.array;
import std.range;
import std.math;
import std.regex : regex;
import std.container;
import std.bigint;
import std.numeric;


void main()
{
  int n, m;
  readf("%s %s\n", &n, &m);
  bool[int] from1, toN;
  foreach (_; 0..m) {
    int a, b;
    readf("%s %s\n", &a, &b);
    if (a == 1) {
      from1[b] = true;
    }
    if (b == n) {
      toN[a] = true;
    }
  }

  bool f;
  foreach (k; from1.keys) {
    if (toN.get(k, 0)) {
      f = true;
    }
  }
  if (f) {
    writeln("POSSIBLE");
  } else {
    writeln("IMPOSSIBLE");
  }
}
