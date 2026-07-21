import std.stdio;
import std.algorithm;
import std.utf;
import std.string;

void main() {
  auto s = readln.chomp.toUTF32.dup;
  auto t = readln.chomp.toUTF32.dup;

  s.sort!"a < b";
  t.sort!"a > b";
  
  if (s < t) {
    writeln("Yes");
  } else {
    writeln("No");
  }
}
