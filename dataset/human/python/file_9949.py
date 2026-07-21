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


auto solve(long A, long B) {
    return (A * B) / gcd(A, B);
}


void main() {
    auto input = stdin.byLine.map!split.joiner;

    long A;
    A = input.front.to!long;
    input.popFront;

    long B;
    B = input.front.to!long;
    input.popFront;

    static if (is(ReturnType!solve == void))
        solve(A, B);
    else {
        auto ans = solve(A, B);

        static if (isFloatingPoint!(ReturnType!solve))
            writeln(format("%.9f", ans));
        else static if (is(ReturnType!solve == bool))
            writeln(ans ? YES : NO);
        else
            writeln(ans);
    }
}
