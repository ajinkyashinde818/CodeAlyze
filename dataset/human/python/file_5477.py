void main() {
    string[] tmp = readln.split;
    string x = tmp[0], y = tmp[1];
    if (x < y) {
        '<'.writeln;
    } else if (x > y) {
        '>'.writeln;
    } else {
        '='.writeln;
    }
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
