import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;

long f (long n, int p) {
  long x;
  n /= p;
  while (n > 0) {
    x += n;
    n /= p;
  }
  return x;
}

void main() {
  long n;
  readf (" %d", &n);
  if (n & 1) {
    writeln (0);
    return;
  }
  n /= 2;
  writeln (f (n, 5));
  //writeln (min (f (n, 2), f (n, 5)));
}
