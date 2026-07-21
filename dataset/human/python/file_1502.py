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
    long N, M;
    scan(N, M);
    auto A = new string[](N);
    auto B = new string[](M);
    foreach (i; 0 .. N)
        scan(A[i]);
    foreach (i; 0 .. M)
        scan(B[i]);
    foreach (i; 0 .. N - M + 1)
        foreach (j; 0 .. N - M + 1)
        {
            bool b = true;
            foreach (k; 0 .. M)
                b = b && (A[i + k][j .. j + M] == B[k]);
            if (b)
            {
                writeln("Yes");
                return;
            }
        }
    writeln("No");
}
