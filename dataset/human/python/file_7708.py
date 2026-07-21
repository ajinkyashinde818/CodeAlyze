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
  auto x = readln.chomp.to!int;
  writeln(x < 1200 ? "ABC" : "ARC");
}
