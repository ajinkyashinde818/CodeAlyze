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
  auto s = readln.chomp.to!(char[]);
  auto q = readln.chomp.to!int;
  auto r = 1;
  string a = "";
  string b = "";
  foreach (_; 0..q) {
    auto x = readln.chomp.split;
    if (x[0].to!int == 1) {
      r *= -1;
    } else {
      if (x[1].to!int == 1) {
        if (r == 1) {
          a = x[2] ~ a;
        } else {
          b = b ~ x[2];
        }
      } else {
        if (r == -1) {
          a = x[2] ~ a;
        } else {
          b = b ~ x[2];
        }
      }
    }
  }
  s = a ~ s ~ b;
  if (r == -1) {
    reverse(s);
  }
  s.writeln;
}
