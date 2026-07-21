void main()
{
    int[] tmp = readln.split.to!(int[]);
    int r = tmp[0], g = tmp[1], b = tmp[2], n = tmp[3];

    int cnt;
    int x = n / r;
    foreach (i; 0 .. x+1)
    {
        int y = (n - r * i) / g;
        foreach (j; 0 .. y+1)
        {
            if ((n - r * i - g * j) % b == 0)
            {
                ++cnt;
            }
        }
    }

    cnt.writeln;
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
