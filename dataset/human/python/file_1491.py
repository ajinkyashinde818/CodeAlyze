import std.stdio, std.conv, std.functional, std.string;
import std.algorithm, std.array, std.container, std.range, std.typecons;
import std.numeric, std.math, std.random;
import core.bitop;

string FMT_F = "%.10f";

static string[] s_rd;
T RD(T = long)() { while(!s_rd.length) s_rd = readln.chomp.split; string res = s_rd[0]; s_rd.popFront; return res.to!T; }
string RDR()() { return readln.chomp; }
T[] ARR(T = long)(in string str, T fix = 0) { auto r = str.split.to!(T[]); r[] += fix; return r; }
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
	auto N = RD;
	auto M = RD;
	auto A = new string[](N);
	auto B = new string[](M);
	foreach (i; 0..N)
		A[i] = RD!string;
	foreach (i; 0..M)
		B[i] = RD!string;

	bool ans;
	(){
	foreach (y; 0..N-M+1)
	{
		foreach (x; 0..N-M+1)
		{
			bool ok = true;
			foreach (i; 0..M)
			{
				foreach (j; 0..M)
				{
					if (A[y+i][x+j] != B[i][j])
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				ans = true;
				return;
			}
		}
	}}();

	writeln(ans ? "Yes" : "No");
	stdout.flush();
	debug readln();
}
