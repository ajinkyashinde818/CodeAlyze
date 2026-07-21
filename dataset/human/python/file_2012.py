import std.stdio, std.array, std.string, std.conv, std.algorithm;
import std.typecons, std.range, std.random, std.math, std.container;
import std.numeric, std.bigint, core.bitop, core.stdc.string;

immutable long MOD = 10^^9 + 7;

void main() {
    auto N = readln.chomp.to!long;
    auto S = readln.chomp;

    auto cnt = new long[](26);

    foreach (i; 0..N) {
        cnt[S[i] - 'a'] += 1;
    }

    long ans = 0;
    foreach (i; 0..N) {
        long tmp = 1;
        foreach (j; 0..26) if (cnt[j] && j != S[i] - 'a') tmp = tmp * (cnt[j] + 1) % MOD;
        ans += tmp;
        ans %= MOD;
        cnt[S[i] - 'a'] -= 1;
    }

    ans = (ans + MOD) % MOD;
    ans.writeln;
}

long powmod(long a, long x, long m) {
    long ret = 1;
    while (x) {
        if (x % 2) ret = ret * a % m;
        a = a * a % m;
        x /= 2;
    }
    return ret;
}
