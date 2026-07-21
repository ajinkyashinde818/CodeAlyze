void main()
{
    long[] tmp = rdRow;
    long d = tmp[0], g = tmp[1];

    Problem[] p = d.rdCol!Problem;
    long result = inf;
    foreach (i; 0 .. 1<<d)
    {
        long cnt, total;
        foreach (j; 0 .. d)
        {
            if (i & (1 << j))
            {
                cnt += p[j].cnt;
                total += 100 * (j + 1) * p[j].cnt + p[j].bonus;
            }
        }

        foreach_reverse (j; 0 .. d)
        {
            if (total >= g) break;
            if (!(i & (1 << j)))
            {
                long diff = g - total;
                long num = min(p[j].cnt-1, (diff+100*(j+1)-1)/(100*(j+1)));
                cnt += num;
                total += 100 * (j + 1) * num;
            }
        }

        if (total >= g) result = min(result, cnt);
    }

    result.writeln;
}

struct Problem
{
    long cnt, bonus;
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
