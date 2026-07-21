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

alias sread = () => readln.chomp();
alias Point2 = Tuple!(long, "y", long, "x");

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

void minAssign(T, U = T)(ref T dst, U src)
{
    dst = cast(T) min(dst, src);
}

void maxAssign(T, U = T)(ref T dst, U src)
{
    dst = cast(T) max(dst, src);
}

enum MOD = (10 ^^ 9) + 7;

void main()
{
    long K, S;
    scan(K, S);
    long ans;
    foreach (x; 0 .. K + 1)
        foreach (y; 0 .. K + 1)
        {
            if (x + y <= S && S - (x + y) <= K)
            {
                ans++;
            }
        }
    writeln(ans);
}
