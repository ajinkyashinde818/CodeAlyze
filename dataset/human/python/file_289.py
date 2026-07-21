import std.algorithm;
import std.bigint;
import std.concurrency;
import std.container;
import std.conv;
import std.functional;
import std.format;
import std.math;
import std.meta;
import std.random;
import std.range;
import std.stdio;
import std.string;
import std.traits;
import std.typecons;


auto solve(long N, long[] A) {
    auto negs = A.filter!"a < 0".array;
    auto abss = A.map!abs.array.sort();
    
    if (negs.length % 2 == 0)
        return abss.sum;
    
    return abss.sum - 2 * abss.front;
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

    static if (is(ReturnType!solve == void))
        solve(N, A);
    else
        solve(N, A).writeln;
}
