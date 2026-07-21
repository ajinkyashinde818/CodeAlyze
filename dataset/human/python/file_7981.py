import std.stdio, std.algorithm, std.range, std.conv, std.string, std.math, std.container, std.typecons;
import core.stdc.stdio;
// foreach, foreach_reverse, writeln

void main() {
	const int MOD = 998244353;
	int k, n;
	scanf("%d%d", &k, &n);
	long[][] r = new long[][](2,k+1);
	long[] dp = new long[n+1];
	dp[0] = 1;
	foreach (i; 0..k) {
		foreach (j; 0..n) {
			(dp[j+1] += dp[j]) %= MOD;
		}
	}
	foreach (i; 0..k+1) {
		r[0][i] = dp[n];
		foreach_reverse (j; 0..n) {
			(dp[j+1] += MOD - dp[j]) %= MOD;
		}
		r[1][i] = (dp[n] + dp[n-1]) % MOD;
		foreach_reverse (j; 0..n) {
			(dp[j+1] += MOD - dp[j]) %= MOD;
		}
		long[] a = dp.dup;
		foreach (j; 0..n) {
			(a[j+1] += a[j]) %= MOD;
		}
		foreach (j; 0..n) {
			(dp[j+1] += a[j]*2) %= MOD;
		}
	}
	foreach (i; 2..2*k+1) {
		int a = 1-i%2;
		int b = -a;
		foreach (j; 1..k+1) {
			int nj = i-j;
			if (1 <= nj && nj <= k) b++;
		}
		b /= 2;
		//writeln(i," ",a," ",b);
		writeln(r[a][b]);
	}
}
