import std.stdio, std.array, std.string, std.conv, std.algorithm;
import std.typecons, std.range, std.random, std.math, std.container;
import std.numeric, std.bigint, core.bitop, core.stdc.stdio;

void main() {
    auto N = readln.chomp.to!int;
    auto A = readln.chomp;

    if (A.front == 'W' || A.back == 'W') {
        writeln(0);
        return;
    }

    immutable long MOD = 10^^9 + 7;
    long ans = 1;
    long cnt = 0;

    foreach (a; A) {
        if (cnt == 0 && a == 'W') {
            writeln(0);
            return;
        } else if (cnt == 0) {
            cnt += 1;
        } else if (a == 'W') {
            if (cnt % 2 == 1) {
                cnt += 1;
            } else {
                ans = ans * cnt % MOD;
                cnt -= 1;
            }
        } else {
            if (cnt % 2 == 1) {
                ans = ans * cnt % MOD;
                cnt -= 1;
            } else {
                cnt += 1;
            }
        }
    }

    if (cnt != 0) {
        writeln(0);
    } else {
        foreach (i; 1..N+1) ans = ans * i % MOD;
        writeln(ans);
    }
}
