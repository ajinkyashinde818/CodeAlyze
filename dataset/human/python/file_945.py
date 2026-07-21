import std.algorithm;
import std.bigint;
import std.concurrency;
import std.container;
import std.conv;
import std.functional;
import std.math;
import std.meta;
import std.random;
import std.range;
import std.stdio;
import std.string;
import std.traits;
import std.typecons;


immutable long MOD = 1000000007;


auto solve(long N, string S) {
    long waysToMakePair = 1;
    
    long floatEdges;
    foreach (c; S) {
        bool open;
        if (c == 'B') {
            // 浮いている紐は奇数でなければならない
            open = (floatEdges & 1) == 0;
        } else {
            // 浮いている紐は奇数でなければならない
            open = (floatEdges & 1) != 0;
        }

        if (open) {
            floatEdges++;
        } else {
            waysToMakePair *= floatEdges;
            waysToMakePair %= MOD;
            floatEdges--;
        }
    }

    if (floatEdges != 0 || waysToMakePair == 0)
        return 0;
    
    long facN = 1;
    foreach (i; 1 .. N + 1) {
        facN *= i;
        facN %= MOD;
    }

    return waysToMakePair * facN % MOD;
}


void main() {
    auto input = stdin.byLine.map!split.joiner;

    long N;
    N = input.front.to!long;
    input.popFront;

    string S;
    S = input.front.to!string;
    input.popFront;

    static if (is(ReturnType!solve == void))
        solve(N, S);
    else
        solve(N, S).writeln;
}
