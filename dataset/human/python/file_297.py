void main()
{
    long n = rdElem;
    long[] a = rdRow;

    bool minus;
    bool zero;
    long result;
    long amin = 1L << 60;
    foreach (x; a)
    {
        result += x.abs;
        amin = min(amin, x.abs);
        if (x < 0) minus ^= true;
        if (x == 0) zero = true;
    }
    if (minus && !zero) result -= 2 * amin;

    result.writeln;
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
