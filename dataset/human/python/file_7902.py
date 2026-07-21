void main() {
    dchar[] s = readln.chomp.to!(dchar[]);
    s.sort!"a < b";
    writeln(s == "abc" ? "Yes" : "No");
}

import std.stdio;
import std.string;
import std.array;
import std.conv;
import std.algorithm;
import std.range;
import std.math;
import std.numeric;
import std.container;
import std.typecons;
import std.ascii;
import std.uni;
