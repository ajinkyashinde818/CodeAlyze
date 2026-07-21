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
  auto n = readln.chomp.to!(char[]).array.count('9');
  writeln(n?"Yes":"No");
}
