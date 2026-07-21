void main()
{
    long[] tmp = readln.split.to!(long[]);
    long a = tmp[0], b = tmp[1];

    writeln(a * b / gcd(a, b));
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
