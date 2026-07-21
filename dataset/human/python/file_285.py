import std.stdio;
import std.algorithm;
import std.conv;
import std.range;
import std.string;
import std.math;

void main() {
	long n = readln.chomp.to!int;
	long[] as = readln.chomp.split(' ').map!(s => s.to!long).array;
	long[] dp = new long[n*2];
	dp[0] =  as[0];
	dp[1] = -as[0];
	for (size_t i = 1; i < n-1; ++i) {
		dp[i*2]   = max(dp[i*2-2] + as[i], dp[i*2-1] - as[i]);
		dp[i*2+1] = max(dp[i*2-2] - as[i], dp[i*2-1] + as[i]);
	}
	dp[n*2-1] = dp[n*2-3] - as[n-1];
	dp[n*2-2] = dp[n*2-4] + as[n-1];
	write(max(dp[2*n-1], dp[2*n-2]));
}
