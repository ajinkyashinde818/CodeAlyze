import std.stdio;
import std.conv;
import std.string;
import std.array;
import std.algorithm;

void main() {
  auto s = readln.chomp.split.map!(to!char).array;

  if (s[0] < s[1]) "<".writeln;
  else if (s[0] > s[1]) ">".writeln;
  else "=".writeln;
}
