import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;

enum int m = 1_000_000_007;

void main() {
  int nt;
  string s;
  readf (" %s", &s);
  auto z = s.splitter;
  immutable n = z.front.to!int;
  z.popFront ();
  string t = z.front;
  auto c = new int[26];
  foreach (i; 0 .. n) {
    int k = t[i].to!int - 97;
    ++c[k];
  }
  debug stderr.writeln (c);
  int r = 1;
  foreach (i; 0 .. 26) {
    long x = r.to!long * (c[i] + 1);
    r = (x % m).to!int;
  }
  r = (r + m - 1) % m;
  writeln (r);
}
