import std.stdio, std.array, std.string, std.conv, std.algorithm;
import std.typecons, std.range, std.random, std.math, std.container;
import std.numeric, std.bigint, core.bitop;

void main() {
    auto S = "0" ~ readln.chomp;
    auto N = S.length.to!int;

    auto dp = new int[][](N+1, 2);
    foreach (i; 0..N+1) dp[i][] = 1 << 29;
    dp[0][0] = 0;

    foreach (i; 0..N) {
        int d = S[N - i - 1] - '0';
        dp[i+1][0] = min(dp[i][0] + d, d == 9 ? 1 << 29 : dp[i][1] + d + 1);
        dp[i+1][1] = min(d == 0 ? 1 << 29 : dp[i][0] + 10 - d, dp[i][1] + 9 - d);
    }

    dp[N][0].writeln;
}
