void main()
{
    int[] tmp = readln.split.to!(int[]);
    int n = tmp[0], m = tmp[1];

    int[][] services = new int[][](n);
    foreach (i; 0 .. m)
    {
        tmp = readln.split.to!(int[]);
        int a = tmp[0] - 1, b = tmp[1] - 1;
        services[a] ~= b;
        services[b] ~= a;
    }

    bool ok;
    foreach (x; services[0])
    {
        foreach (y; services[x])
        {
            if (y == n - 1)
            {
                ok = true;
            }
        }
    }

    writeln(ok ? "POSSIBLE" : "IMPOSSIBLE");
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
