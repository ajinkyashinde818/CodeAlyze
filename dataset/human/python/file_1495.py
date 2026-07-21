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
  int n, m;
  readf("%s %s\n", &n, &m);
  auto a = new char[][](n, n);
  auto b = new char[][](m, m);
  foreach (i; 0..n) {
    a[i] = readln.chomp.to!(char[]);
  }
  foreach (i; 0..m) {
    b[i] = readln.chomp.to!(char[]);
  }

  bool f;
  foreach (i; 0..n-m+1) {
    a:foreach (j; 0..n-m+1) {
      foreach (x; 0..m) {
        foreach (y; 0..m) {
          if (a[i+x][j+y] != b[x][y]) {
            continue a;
          }
        }
      }
      f = true;
    }
  }

  if (f) {
    writeln("Yes");
  } else {
    writeln("No");
  }
}
