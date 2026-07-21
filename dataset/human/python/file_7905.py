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
  auto s = readln.chomp;
  int[char] k;
  foreach (e; s) {
    k[e]++;
  }
  if (k.keys.length == 3) {
    writeln("Yes");
  } else {
    writeln("No");
  }
}
