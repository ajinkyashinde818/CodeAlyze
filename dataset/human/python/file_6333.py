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

enum MAX = 1_000_100;
ulong MOD = 1_000_000_007;
ulong INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias Pair = Tuple!(long, "a", long, "b");
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);

void main()
{
    auto n = lread();
    if(n % 2)
    {
        writeln(0);
    }
    else
    {
        long five_cnt;
        n /= 2;
        while(n > 0)
        {
            n /= 5;
            five_cnt += n;
        }
        writeln(five_cnt);
    }
}

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
