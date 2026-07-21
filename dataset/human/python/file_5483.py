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
import std.ascii;


void main()
{
  char x, y;
  readf("%s %s\n", &x, &y);
  if (x < y) {
    writeln("<");
  } else if (x > y) {
    writeln(">");
  } else {
    writeln("=");
  }
}
