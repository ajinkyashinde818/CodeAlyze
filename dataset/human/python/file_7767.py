void main()
{
    long[] tmp = rdRow;
    long n = tmp[0], k = tmp[1], s = tmp[2];

    long t;
    if (n - k)
    {
        if (s == 10L ^^ 9) t = 1;
        else t = 10L ^^ 9;
    }
    foreach (i; 0 .. n)
    {
        if (i < k) s.write;
        else t.write;

        if (i == n - 1) writeln;
        else " ".write;
    }
}

T rdElem(T = long)()
{
    //import std.stdio : readln;
    //import std.string : chomp;
    //import std.conv : to;

    return readln.chomp.to!T;
}

alias rdStr = rdElem!string;

dchar[] rdDchar()
{
    //import std.conv : to;

    return rdStr.to!(dchar[]);
}

T[] rdRow(T = long)()
{
    //import std.stdio : readln;
    //import std.array : split;
    //import std.conv : to;

    return readln.split.to!(T[]);
}

T[] rdCol(T = long)(long col)
{
    //import std.range : iota;
    //import std.algorithm : map;
    //import std.array : array;

    return iota(col).map!(x => rdElem!T).array;
}

T[][] rdMat(T = long)(long col)
{
    //import std.range : iota;
    //import std.algorithm : map;
    //import std.array : array;

    return iota(col).map!(x => rdRow!T).array;
}

void wrMat(T = long)(T[][] mat)
{
    //import std.stdio : write, writeln;

    foreach (row; mat)
    {
        foreach (j, compo; row)
        {
            compo.write;
            if (j == row.length - 1) writeln;
            else " ".write;
        }
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
