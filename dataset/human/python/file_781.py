import std.stdio, std.conv, std.string, std.algorithm, std.math, std.array, std.container;

void main() {
  int n, r;
  readf("%d %d\n", &n, &r);
  int ir;
  if(n < 10) ir = r + 100*(10-n);
  else ir = r;
  writeln(ir);
}
