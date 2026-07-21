void main()
{
    long n = readln.chomp.to!long;

    if (n & 1)
    {
        0.writeln;
    }
    else
    {
        long cnt;
        long d = 10;
        while (d <= n)
        {
            cnt += n / d;
            d *= 5;
        }

        cnt.writeln;
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
