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
	auto M = RD!long;

	auto cnt = new long[](N);
	foreach (i; 0..M)
	{
		auto a = RD!long;
		auto b = RD!long;
		if (a == 1) ++cnt[b];
		else if (b == N) ++cnt[a];
	}
	bool ans = false;
	foreach (e; cnt)
	{
		if (e >= 2) ans = true;
	}

	writeln(ans ? "POSSIBLE" : "IMPOSSIBLE");
	stdout.flush();
}
