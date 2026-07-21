import std.algorithm,
       std.string,
       std.array,
       std.stdio,
       std.range,
       std.conv;

long abs(long x) {
  return x * (x < 0 ? -1 : 1);
}

void main() {
  long   N = readln.chomp.to!long;
  long[] a = readln.chomp.split.to!(long[]);
  long ans = long.max;

  long x, y;

  for (size_t i = 0; i < N - 1; i++) {
    if (i == 0) {
      x = a[i];
      y = a[1..$].sum;
    } else {
      x += a[i];
      y -= a[i];
    }

    long z = abs(x - y);

    if (z < ans) {
      ans = z;
    }
  }

  writeln(ans);
}
