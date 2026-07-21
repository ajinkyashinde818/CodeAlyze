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

enum MOD = 10 ^^ 9 + 7;

void main()
{
    long N = lread();
    auto A = aryread();
    auto dp = new long[][](N + 1, 2);
    dp[0][] = dp[1][] = long.min / 2;
    dp[0][0] = 0;
    // writeln(dp[0]);
    foreach (i; 0 .. N)
    {
        dp[i + 1][0] = dp[i + 1][0].max(dp[i][0] + A[i]);
        dp[i + 1][0] = dp[i + 1][0].max(dp[i][1] - A[i]);

        dp[i + 1][1] = dp[i + 1][1].max(dp[i][0] - A[i]);
        dp[i + 1][1] = dp[i + 1][1].max(dp[i][1] + A[i]);
    }
    writeln(dp[N][0]);
}
