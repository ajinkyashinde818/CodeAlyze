import std.stdio, std.conv, std.functional, std.string;
import std.algorithm, std.array, std.container, std.range, std.typecons;
import std.bigint, std.numeric, std.math, std.random;
import core.bitop;

string FMT_F = "%.10f";

static File _f;
void file_io(string fn) { _f = File(fn, "r"); }
static string[] s_rd;
T _RD(T = long)() { while(!s_rd.length) s_rd = readln.chomp.split; string res = s_rd[0]; s_rd.popFront; return res.to!T; }
T _RD(T = long)(File f) { while(!s_rd.length) s_rd = f.readln.chomp.split; string res = s_rd[0]; s_rd.popFront; return res.to!T; }
T[] _RDA(T = long)(T fix = 0) { auto r = readln.chomp.split.to!(T[]); r[] += fix; return r; }
T[] _RDA(T = long)(File f, T fix = 0) { auto r = f.readln.chomp.split.to!(T[]); r[] += fix; return r; }
T RD(T = long)() { if (_f.isOpen) return _RD!T(_f); else return _RD!T; }
T[] RDA(T = long)(T fix = 0) { if (_f.isOpen)  return _RDA!T(_f, fix); else return _RDA!T(fix); }

size_t[] MAKE_IDX(alias less = "a < b", Range)(Range range) { auto idx = new size_t[](range.length); makeIndex!(less)(range, idx); return idx;}
size_t MIN_POS(alias less = "a < b", Range)(Range range) { auto r = minPos!(less)(range); return range.length - r.length; }

void chmin(T)(ref T x, T y) { x = min(x, y); } void chmax(T)(ref T x, T y) { x = max(x, y); }
bool inside(T)(T x, T b, T e) { return x >= b && x < e; }
T lcm(T)(T x, T y) { return x * (y / gcd(x, y)); }

long mod = 10^^9 + 7;
//long mod = 998_244_353;
//long mod = 1_000_003;
void moda(T)(ref T x, T y) { x = (x + y) % mod; }
void mods(T)(ref T x, T y) { x = ((x + mod) - (y % mod)) % mod; }
void modm(T)(ref T x, T y) { x = (x * y) % mod; }
void modpow(T)(ref T x, T y) { if (!y) { x = 1; return; } auto t = x; x.modpow(y>>1); x.modm(x); if (y&1) x.modm(t); }
void modd(T)(ref T x, T y) { x.modm(y.modpow(mod - 2)); }

void main()
{
	auto N = RD;
	auto K = RD;
	auto A = RDA(-1);
	
	auto list = new long[][](65, N);
	foreach (i; 0..N)
	{
		list[0][i] = A[i];
	}

	foreach (i; 1..65)
	{
		foreach (j; 0..N)
		{
			auto mid = list[i-1][j];
			list[i][j] = list[i-1][mid];
		}
	}
	debug writeln(list);

	long pos;
	foreach (i; 0..64)
	{
		auto bit = 1L << i;
		if (K & bit)
		{
			pos = list[i][pos];
			debug writeln("pos:", pos);
		}
	}

	writeln(pos+1);
	stdout.flush;
	debug readln;
}
