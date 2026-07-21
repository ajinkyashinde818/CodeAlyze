import std.stdio, std.conv, std.string;
import std.algorithm, std.array, std.container;
import std.numeric, std.math;
import core.bitop;

T RD(T = string)() { static string[] ss; while(!ss.length) ss = readln.chomp.split; string res = ss[0]; ss.popFront; return res.to!T; }
string RDR()() { return readln.chomp; }

long mod = pow(10, 9) + 7;
long moda(long x, long y) { return (x + y) % mod; }
long mods(long x, long y) { return ((x + mod) - (y % mod)) % mod; }
long modm(long x, long y) { return (x * y) % mod; }

void main()
{
	auto N = RD!long;
	auto a = RDR.split.to!(long[]);

	auto dp = new long[](N+1);
	dp[0] = 0;
	foreach (i, e; a)
	{
		dp[i+1] = dp[i] + e;
	}
	long best = long.max;
	foreach (e; dp[1..$-1])
	{
		auto x = e;
		auto y = dp[N] - e;
		if (abs(x - y) < best)
		{
			best = abs(x - y);
		}
	}

	writeln(best);
	stdout.flush();
}
