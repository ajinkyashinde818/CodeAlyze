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
  long a, b;
  readf("%s %s\n", &a, &b);
  writeln((a * b) / gcd(a, b));
}
