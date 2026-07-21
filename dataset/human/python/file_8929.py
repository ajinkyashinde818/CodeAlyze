import std.stdio, std.conv, std.functional, std.string;
import std.algorithm, std.array, std.container, std.typecons;
import std.numeric, std.math;
import core.bitop;

string FMT_F = "%.10f";

static string[] s_rd;
T RD(T = long)() { while(!s_rd.length) s_rd = readln.chomp.split; string res = s_rd[0]; s_rd.popFront; return res.to!T; }
string RDR()() { return readln.chomp; }
T[] ARR(T = long)(in string str, T fix = 0) { auto r = str.split.to!(T[]); r[] += fix; return r; }
size_t[] MAKE_IDX(alias less = "a < b", Range)(Range range) { auto idx = new size_t[](range.length); makeIndex!(less)(range, idx); return idx;}
size_t MIN_POS(alias less = "a < b", Range)(Range range) { auto r = minPos!(less)(range); return range.length - r.length; }

bool inside(T)(T x, T b, T e) { return x >= b && x < e; }
bool minimize(T)(ref T x, T y) { if (x > y) { x = y; return true; } else { return false; } }
bool maximize(T)(ref T x, T y) { if (x < y) { x = y; return true; } else { return false; } }

long mod = 10^^9 + 7;
void moda(ref long x, long y) { x = (x + y) % mod; }
void mods(ref long x, long y) { x = ((x + mod) - (y % mod)) % mod; }
void modm(ref long x, long y) { x = (x * y) % mod; }

void main()
{
	auto S = RD!string;
	string[] str = ["dream", "dreamer", "erase", "eraser"];
	long pos = S.length, lastPos = pos;
	bool isWrong;
	while (pos != 0)
	{
		foreach (e; str)
		{
			auto len = e.length;
			if (pos-len >= 0 && S[pos-len..pos] == e)
			{
				pos -= len;
				break;
			}
		}
		if (pos == lastPos)
		{
			isWrong = true;
			break;
		}
		lastPos = pos;
	}
	writeln(isWrong ? "NO" : "YES");
	stdout.flush();
	//readln();
}
