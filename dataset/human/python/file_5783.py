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
  auto n = readln.chomp.to!int;
  auto a = readln.chomp.split.to!(int[]);
  auto b = readln.chomp.split.to!(int[]);
  auto c = readln.chomp.split.to!(int[]);
  auto prev = -1;
  int res;
  foreach (i; 0..n) {
    res += b[a[i]-1];
    if (prev + 1 == a[i]) {
      res += c[a[i]-2];
    }
    prev = a[i];
  }
  res.writeln;
}
