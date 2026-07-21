import std.stdio;
import std.conv;
import std.string;
import std.typecons;
import std.algorithm;
import std.array;
import std.range;
import std.math;
import std.regex;
import std.container;
import std.bigint;
import std.ascii;


void main()
{
  int a, b, c;
  readf("%s %s %s\n", &a, &b, &c);
  writeln(b + min(a+b+1, c));
}
