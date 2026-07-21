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
alias Goods = Tuple!(long, "w", long, "v");

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
    auto s = sread();
    long cnt, left, right = s.length - 1;
    bool batch = true;
    while (left <= right)
    {
        if (s[left] == s[right])
            left++, right--;
        else if (s[left] == 'x')
            cnt++, left++;
        else if (s[right] == 'x')
            cnt++, right--;
        else
        {
            batch = false;
            break;
        }
    }
    if (batch)
        writeln(cnt);
    else
        writeln(-1);
}
