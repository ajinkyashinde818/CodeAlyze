import core.bitop;
import std.algorithm;
import std.ascii;
import std.bigint;
import std.conv;
import std.functional;
import std.math;
import std.numeric;
import std.range;
import std.stdio;
import std.string;
import std.random;
import std.typecons;
import std.container;

alias sread = () => readln.chomp();
ulong MOD = 1_000_000_007;
ulong INF = 1_000_000_000_000;
alias Score = Tuple!(long, "p", long, "c");

T lread(T = long)()
{
    return readln.chomp.to!T();
}

T[] aryread(T = long)()
{
    return readln.split.to!(T[])();
}

void scan(TList...)(ref TList Args)
{
    auto line = readln.split();
    foreach (i, T; TList)
    {
        T val = line[i].to!(T);
        Args[i] = val;
    }
}

void main()
{
    long d, g;
    scan(d, g);
    auto scores = new Score[](d);
    foreach (ref e; scores)
    {
        long r, c;
        scan(r, c);
        e = Score(r, c);
    }
    auto m = INF;
    foreach (i; iota(1 << d))
    {
        long p, plus, moves;
        auto b = i.bitary(d);
        foreach (j; iota(b.length))
        {
            if (b[j])
            {
                p += scores[j].p * 100 * (j + 1);
                p += scores[j].c;
                moves += scores[j].p;
            }
            else
                plus = j;
        }
        long n = scores[plus].p;
        while (n > 1 && p < g)
        {
            p += 100 * (plus + 1);
            moves++, n--;
        }
        // moves.writeln();
        if (p >= g)
            m = min(moves, m);
    }
    m.writeln();
}

auto bitary(long n, long m)
{
    auto b = new long[](m);
    long i;
    while (n > 0)
    {
        b[i++] = n % 2;
        n = n >> 1;
    }
    b.reverse();
    return b;
}
