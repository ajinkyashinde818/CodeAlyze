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
  auto n = readln.chomp.to!int;
  auto a = readln.chomp.split.to!(long[]);

  auto lsum = a[0];
  auto rsum = a.sum - lsum;
  auto res = abs(lsum - rsum).to!long;
  foreach (i; 1..n-1) {
    lsum += a[i];
    rsum -= a[i];
    auto d = abs(lsum - rsum).to!long;
    if (d < res) {
      res = d;
    }
  }
  res.writeln;
}
