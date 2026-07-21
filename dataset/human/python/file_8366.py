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
  int k, n;
  readf("%s %s\n", &k, &n);
  auto a = readln.chomp.split.to!(int[]);
  auto res = int.max;
  foreach (i; 0..n) {
    auto x = i + n - 1;
    auto y = i - n + 1;
    if (x >= n) {
      x -= n;
    }
    if (y < 0) {
      y += n;
    }

    auto d1 = a[x] - a[i];
    auto d2 = a[i] - a[y] + k;
    if (d1 > k) {
      d1 -= k;
    }
    if (d1 < 0) {
      d1 += k;
    }
    if (d2 > k) {
      d2 -= k;
    }
    if (d2 < 0) {
      d2 += k;
    }

    res = min(res, d1);
    res = min(res, d2);
  }
  res.writeln;
}
