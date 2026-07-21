import std.algorithm;
import std.array;
import std.conv;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

int solve (int n)
{
	readln;
	auto a = readln.splitter.map !(to !(int)).array;
	auto b = readln.splitter.map !(to !(int)).array;
	int res = 0;
	foreach_reverse (bit; 0..29)
	{
		int lim = 1 << bit;
		a[] &= (lim * 2 - 1);
		b[] &= (lim * 2 - 1);
		sort !(q{a < b}) (a);
		sort !(q{a > b}) (b);
		debug {writeln (a); writeln (b);}
		int cur = 0;

//		000  001  010  011  100  101  110  111
//		111  110  101  100  011  010  001  000
//		          010
//		111  110][101  100  011  010][001  000
		int lo = 0;
		int me = 0;
		int hi = 0;
		foreach (c; a)
		{
			while (lo < n && b[lo] + c >= lim * 3)
			{
				lo += 1;
			}
			while (me < n && b[me] + c >= lim * 2)
			{
				me += 1;
			}
			while (hi < n && b[hi] + c >= lim * 1)
			{
				hi += 1;
			}
			cur ^= (lo - 0);
			cur ^= (hi - me);
			cur &= 1;
			debug {writeln (lo, " ", me, " ", hi, " ", cur);}
		}
		res += cur << bit;
	}
	return res;
}

void main ()
{
	int n;
	while (readf (" %s", &n) > 0)
	{
		writeln (solve (n));
	}
}
