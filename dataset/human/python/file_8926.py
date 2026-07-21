import std.stdio;
import std.algorithm;
import std.range;
import std.conv;
import std.format;
import std.array;
import std.math;
import std.string;
import std.container;

string[] C = ["dreamer", "eraser", "dream", "erase"];

bool judge(string sub_str) {
  if (sub_str.length == 0)
    return true;

  bool ok = false;
  foreach(c; C) {
    if (sub_str.length < c.length)
      continue;

    if (sub_str[0..c.length] == c)
      ok = ok || judge(sub_str[c.length..$]);
  }

  return ok;
}

void main() {
  string S; readlnTo(S);
  writeln(judge(S) ? "YES" : "NO");
}

// helpers
void readlnTo(T...)(ref T t) {
  auto s = readln.split;
  assert(s.length == t.length);
  foreach(ref ti; t) {
    ti = s[0].to!(typeof(ti));
    s = s[1..$];
  }
}
