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
import std.ascii;


void main()
{
  int n, r;
  readf("%s %s\n", &n, &r);
  if (n >= 10) {
    r.writeln;
  } else {
    writeln(r + 100 * (10 - n));
  }
}
