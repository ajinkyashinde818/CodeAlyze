import core.bitop;
import std.algorithm;
import std.array;
import std.ascii;
import std.container;
import std.conv;
import std.format;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

void main()
{
  string str = readln.chomp;
  writeln = str.indexOf("9") == -1 ? "No" : "Yes";
}
