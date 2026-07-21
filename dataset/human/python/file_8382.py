import std.stdio, std.array, std.string, std.conv, std.algorithm;
import std.typecons, std.range, std.random, std.math, std.container;
import std.numeric, std.bigint, core.bitop, core.stdc.stdio;

void main() {
    auto s = readln.split.map!(to!int);
    auto K = s[0];
    auto N = s[1];
    auto A = readln.split.map!(to!int).array;

    int ans = 1 << 29;

    foreach (i; 0..N) {
        auto a = A[i];
        auto b = A[(i+1)%N];
        auto c = (b > a) ? b - a : b + K - a;
        ans = min(ans, K - c);
    }

    ans.writeln;
}
