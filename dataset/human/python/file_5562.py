void main()
{
    string s = rdStr;

    long len = s.length;
    long l, r = len - 1;
    long cnt;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            ++l, --r;
        }
        else
        {
            if (s[l] == 'x')
            {
                ++cnt;
                ++l;
            }
            else if (s[r] == 'x')
            {
                ++cnt;
                --r;
            }
            else
            {
                writeln(-1);
                return;
            }
        }
    }

    cnt.writeln;
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
