import std.stdio;
import std.algorithm;
import std.array;
import std.conv;
import std.string;

void main() {
  string str = readln.chomp;

  // array.lengthの返り値の型はulongなので
  // intに代入しようとすると(dmd64 v2.070.1では)CEになる
  int p = str.length.to!int;

  while (p > 0) {
    if (str[(p - 7)..p] == "dreamer") {
      p -= 7;
    }
    else if (str[(p - 6)..p] == "eraser") {
      p -= 6;
    }
    else if (str[(p - 5)..p] == "erase") {
      p -= 5;
    }
    else if (str[(p - 5)..p] == "dream") {
      p -= 5;
    }
    else {
      p = -1;
    }
  }

  if (p == 0) {
    writeln("YES");
  }
  else {
    writeln("NO");
  }

  return;
}
