import std.functional,
       std.algorithm,
       std.bigint,
       std.string,
       std.traits,
       std.array,
       std.range,
       std.stdio,
       std.conv;

void main() {
  string[] XY = readln.chomp.split.to!(string[]);
  string X = XY[0],
         Y = XY[1];

  if (X < Y) {
    writeln("<");
  } else if (X > Y) {
    writeln(">");
  } else {
    writeln("=");
  }
}
