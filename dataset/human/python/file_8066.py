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
  int k, s;
  readf("%s %s\n", &k, &s);

  long res;

  foreach (x; 0..k+1) {
    foreach (y; 0..k+1) {
      auto z = s - x - y;
      if (z > k || z < 0) continue;
      if (x + y + z == s) {
        res++;
      }
    }
  }

  res.writeln;
}
