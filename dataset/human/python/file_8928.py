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
  auto s = readln.chomp;
  auto p = ["dreamer", "dream", "eraser", "erase"];
  int i = s.length.to!int;
  a:while (i > 0) {
    foreach (e; p) {
      if (e.length > i) {
        continue;
      }

      if (s[i-e.length..i] == e) {
        i -= e.length;
        continue a;
      }
    }
    break a;
  }

  if (i == 0) {
    writeln("YES");
  } else {
    writeln("NO");
  }
}
