import std.algorithm;
import std.bigint;
import std.concurrency;
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


auto solve(long N, long[] A, long[] B, long[] C) {
    A = [long.init] ~ A;
    B = [long.init] ~ B;
    C = [long.init] ~ C;

    long ans;
    size_t lastMeal;
    foreach (i; 1 .. cast(size_t) N + 1) {
        size_t nowMeal = cast(size_t) A[i];
        ans += B[nowMeal];
        if (lastMeal + 1 == nowMeal)
            ans += C[lastMeal];
        lastMeal = nowMeal;
    }
    return ans;
}


void main() {
    auto input = stdin.byLine.map!split.joiner;

    long N;
    N = input.front.to!long;
    input.popFront;

    long[] A = new long[](cast(size_t) (N));
    foreach (i; 0 .. cast(size_t) (N)) {
        A[i] = input.front.to!long;
        input.popFront;
    }

    long[] B = new long[](cast(size_t) (N));
    foreach (i; 0 .. cast(size_t) (N)) {
        B[i] = input.front.to!long;
        input.popFront;
    }

    long[] C = new long[](cast(size_t) (N-1));
    foreach (i; 0 .. cast(size_t) (N-1)) {
        C[i] = input.front.to!long;
        input.popFront;
    }

    static if (is(ReturnType!solve == void))
        solve(N, A, B, C);
    else
        solve(N, A, B, C).writeln;
}
