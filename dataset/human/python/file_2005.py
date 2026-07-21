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
ulong bignum = 1_000_000_007;
alias Pair = Tuple!(long, "number", long, "times");

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
    auto n = lread();
    auto s = sread();
    long[dchar] alf;
    long ans = 1;
    foreach (e; s)
    {
        alf[e]++;
    }
    sort(cast(ubyte[]) s);
    foreach (e; s.uniq)
    {
        ans *= alf[e] + 1;
        ans %= bignum;
    }
    (ans - 1).writeln();
}
