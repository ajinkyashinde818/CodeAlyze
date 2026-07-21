void main()
{
    long n, k;
    rdVals(n, k);
    long[] a = rdRow;


    Edge[long] list;
    long pos;
    long l;
    long rem = k;

    if (k <= n)
    {
        foreach (i; 0 .. k)
        {
            pos = a[pos] - 1;
        }
    }
    else
    {
        foreach (i; 0 .. k)
        {
            if (pos in list)
            {
                rem -= list[pos].cost;
                l = i - list[pos].cost;
                break;
            }
            else
            {
                list[pos] = Edge(a[pos]-1, i);
                pos = a[pos] - 1;
            }
        }

        rem %= l;
        foreach (i; 0 .. rem)
        {
            pos = list[pos].to;
        }
    }

    pos += 1;

    pos.writeln;
}

struct Edge
{
    long to, cost;
}

enum long mod = 10^^9 + 7;
enum long inf = 1L << 60;
enum double eps = 1.0e-9;

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
import std.mathspecial;
import std.traits;
import std.container;
import std.functional;
import std.typecons;
import std.ascii;
import std.uni;
import core.bitop;
