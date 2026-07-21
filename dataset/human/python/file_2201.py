import std.stdio, std.conv, std.string;
import std.algorithm, std.array, std.container;
import std.numeric, std.math;
import core.bitop;

string my_readln() { return chomp(readln()); }

long mod = pow(10, 9) + 7;
long moda(long x, long y) { return (x + y) % mod; }
long mods(long x, long y) { return ((x + mod) - (y % mod)) % mod; }
long modm(long x, long y) { return (x * y) % mod; }

void main()
{
	auto tokens = my_readln.split;
	auto D = tokens[0].to!long;
	auto G = tokens[1].to!long;

	ulong[] p, c;
	foreach (i; 0..D)
	{
		auto tokens2 = my_readln.split;
		p ~= tokens2[0].to!ulong;
		c ~= tokens2[1].to!ulong;
	}

	long f(ulong[] used, long score, long cnt)
	{
		if (score <= 0) return cnt;
		
		long r = long.max;
		foreach (i, e; used)
		{
			if (e == 1) continue;

			auto x = score / ((i + 1) * 100) + (score % ((i + 1) * 100) == 0 ? 0 : 1);
			if (x <= p[i])
			{
				r = min(r, cnt + x);
			}
			else
			{
				auto nUsed = used.dup;
				nUsed[i] = 1;
				r = min(r, f(nUsed, score - ((i + 1) * 100 * p[i] + c[i]), cnt + p[i]));
			}
		}
		
		return r;
	}

	writeln(f(new ulong[](D), G, 0));
	stdout.flush();
}
