void main()
{
    long n = readln.chomp.to!long;
    long[] a = readln.split.to!(long[]);

    long snuke = a[0], raccoon = a[1..$].sum;
    long diff = abs(snuke-raccoon);
    foreach (i; 1 .. n-1)
    {
        snuke += a[i], raccoon -= a[i];
        diff = min(diff, abs(snuke - raccoon));
    }

    diff.writeln;
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
