void main()
{
    dchar[] s = rdDchar;

    bool rev;
    dchar[] front, back;
    long q = rdElem;
    foreach (i; 0 .. q)
    {
        string[] p = rdRow!string;
        if (p.length == 1)
        {
            rev = !rev;
        }
        else
        {
            long f = p[1].to!long - 1;
            dchar c = p[2].to!dchar;

            if (f)
            {
                if (rev) front ~= c;
                else back ~= c;
            }
            else
            {
                if (rev) back ~= c;
                else front ~= c;
            }
        }
    }

    if (rev)
    {
        s.reverse();
        back.reverse();
        writeln(back, s, front);
    }
    else
    {
        front.reverse();
        writeln(front, s, back);
    }
}

enum long mod = 10^^9 + 7;
enum long inf = 1L << 60;

T rdElem(T = long)()
if (!is(T == struct))
{
    return readln.chomp.to!T;
}

alias rdStr = rdElem!string;
alias rdDchar = rdElem!(dchar[]);

T rdElem(T)()
if (is(T == struct))
{
    T result;
    string[] input = rdRow!string;
    assert(T.tupleof.length == input.length);
    foreach (i, ref x; result.tupleof)
    {
        x = input[i].to!(typeof(x));
    }
    return result;
}

T[] rdRow(T = long)()
{
    return readln.split.to!(T[]);
}

T[] rdCol(T = long)(long col)
{
    return iota(col).map!(x => rdElem!T).array;
}

T[][] rdMat(T = long)(long col)
{
    return iota(col).map!(x => rdRow!T).array;
}

void rdVals(T...)(ref T data)
{
    string[] input = rdRow!string;
    assert(data.length == input.length);
    foreach (i, ref x; data)
    {
        x = input[i].to!(typeof(x));
    }
}

void wrMat(T = long)(T[][] mat)
{
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
import std.traits;
import std.container;
import std.functional;
import std.typecons;
import std.ascii;
import std.uni;
