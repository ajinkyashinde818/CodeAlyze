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


void main()
{
  int r, g, b, n;
  readf("%d %d %d %d\n", &r, &g, &b, &n);
  
  int res;
  foreach (x; iota(0, n+1, r)) {
    foreach (y; iota(0, n+1, g)) {
      immutable t = n - (x + y);
      if (t < 0) {
        break;
      }
      if (t % b == 0) {
        res++;
      }
    }
  }
  res.writeln;
}
