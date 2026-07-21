import std.stdio, std.conv, std.functional, std.string;
import std.algorithm, std.array, std.container, std.range, std.typecons;
import std.numeric, std.math, std.random;
import core.bitop;

string FMT_F = "%.15f";

static string[] s_rd;
T RD(T = long)() { while(!s_rd.length) s_rd = readln.chomp.split; string res = s_rd[0]; s_rd.popFront; return res.to!T; }
string RDR()() { return readln.chomp; }
T[] ARR(T = long)(in string str, T fix = 0) { auto r = str.split.to!(T[]); r[] += fix; return r; }
T[] RDA(T = long)(T fix = 0) { auto r = readln.chomp.split.to!(T[]); r[] += fix; return r; }
T[][] RDA2(T = long)(size_t n, T[] fix = []) { auto r = new T[][](n); foreach (i; 0..n) { r[i] = readln.chomp.split.to!(T[]); foreach (j, e; fix) r[i][j] += e; } return r; }
size_t[] MAKE_IDX(alias less = "a < b", Range)(Range range) { auto idx = new size_t[](range.length); makeIndex!(less)(range, idx); return idx;}
size_t MIN_POS(alias less = "a < b", Range)(Range range) { auto r = minPos!(less)(range); return range.length - r.length; }

bool inside(T)(T x, T b, T e) { return x >= b && x < e; }
long lcm(long x, long y) { return x * y / gcd(x, y); }

long mod = 10^^9 + 7;
//long mod = 998244353;
//long mod = 1_000_003;
void moda(ref long x, long y) { x = (x + y) % mod; }
void mods(ref long x, long y) { x = ((x + mod) - (y % mod)) % mod; }
void modm(ref long x, long y) { x = (x * y) % mod; }

void main()
{
	auto s = RD!string;
	long l = 0, r = s.length-1;
	long ans;
	while (r-l > 0)
	{
		if (s[l] == s[r])
		{
			++l; --r;
		}
		else if (s[l] == 'x')
		{
			++ans;
			++l;
		}
		else if (s[r] == 'x')
		{
			++ans;
			--r;
		}
		else
		{
			ans = -1;
			break;
		}
	}

	writeln(ans);
	stdout.flush();
	debug readln();
}
