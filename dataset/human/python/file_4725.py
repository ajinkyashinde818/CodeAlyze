import std.stdio;
import std.algorithm;
import std.conv;
import std.array;
import std.string;
import std.math;
import std.functional;
import std.range;
import std.typecons;
import std.format;

void main(string[] args) {
  solve(readln.chomp, readln.chomp).writeln;
}

auto solve(string line1, string line2) {
  string s_prime = line1.to!(dchar[]).sort!"a < b".to!string;
  string t_prime = line2.to!(dchar[]).sort!"a > b".to!string;
  return s_prime < t_prime ? "Yes" : "No";
} unittest {
  assert(solve("yx", "axy") == "Yes", "1");
  assert(solve("ratcode", "atlas") == "Yes", "2");
  assert(solve("cd", "abc") == "No", "3");
  assert(solve("w", "ww") == "Yes", "4");
  assert(solve("zzz", "zzz") == "No", "5");
}
