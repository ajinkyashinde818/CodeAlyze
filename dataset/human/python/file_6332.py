import std.algorithm;
import std.bigint;
import std.bitmanip;
import std.concurrency : generator = Generator, yield;
import std.container;
import std.conv;
import std.functional;
import std.format;
import std.math;
import std.meta;
import std.numeric;
import std.random;
import std.range;
import std.stdio;
import std.string;
import std.traits;
import std.typecons;


ulong log5(ulong x) {
    ulong y = 0;
    while (x > 5) {
        y++;
        x /= 5;
    }
    return y;
}


auto solve(ulong N) {
    if (N % 2 == 1)
        return 0;

    ulong k = log5(N);

    ulong ans;
    foreach (ulong i; 1 .. k + 1) {
        ulong q = N / (2 * 5 ^^ i);
        ans += i * (q - q / 5);
    }
    return ans;
}


void main() {
    auto input = stdin.byLine.map!split.joiner;

    ulong N;
    N = input.front.to!ulong;
    input.popFront;

    static if (is(ReturnType!solve == void))
        solve(N);
    else {
        auto ans = solve(N);

        static if (isFloatingPoint!(ReturnType!solve))
            writeln(format("%.9f", ans));
        else static if (is(ReturnType!solve == bool))
            writeln(ans ? YES : NO);
        else
            writeln(ans);
    }
}
