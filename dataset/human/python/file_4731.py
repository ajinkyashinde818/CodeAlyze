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
  auto s = sort(readln.chomp.to!(char[]).array).to!string;
  auto t = sort(readln.chomp.to!(char[]).array);
  t.reverse;
  auto td = t.to!string;
  if (s < td) {
    writeln("Yes");
  } else {
    writeln("No");
  }
}
