import std.stdio, std.string, std.conv, std.algorithm, std.range, std.math;

void main() {
  dchar[] a = readln.chomp.to!(dchar[]), b = readln.chomp.to!(dchar[]);

  sort(a);
  sort!((x, y) { return x > y; })(b);
  if (a < b) {
    writeln("Yes");
  } else {
    writeln("No");
  }
}
