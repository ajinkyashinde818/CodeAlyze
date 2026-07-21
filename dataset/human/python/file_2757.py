import std.algorithm;
import std.array;
import std.conv;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

immutable int limit = 51;

long transform (long m, int d)
{
	foreach (i; 0..limit)
	{
		if (m & (1L << i))
		{
			m |= 1L << (i % d);
		}
	}
	return m;
}

bool canTransform (long m, int b, int med)
{
	foreach_reverse (d; 1..med + 1)
	{
		m = transform (m, d);
	}
	return (m >> b) & 1;
}

long solve (int n, int [] a, int [] b)
{
	long res = 0;
	auto c = a.map !(x => 1L << x).array;
	foreach_reverse (d; 1..limit)
	{
		bool canSkip = true;
		foreach (i; 0..n)
		{
			if (!canTransform (c[i], b[i], d - 1))
			{
				canSkip = false;
			}
		}
		if (canSkip)
		{
			continue;
		}
		res += 1L << d;
		foreach (i; 0..n)
		{
			c[i] = transform (c[i], d);
		}
		debug {writefln ("%s %(%b %)", res, c);}
	}
	foreach (i; 0..n)
	{
		if (!canTransform (c[i], b[i], 0))
		{
			return -1;
		}
	}
	return res;
}

void main ()
{
	int n;
	while (readf (" %s", &n) > 0)
	{
		readln;
		auto a = readln.splitter.map !(to !(int)).array;
		auto b = readln.splitter.map !(to !(int)).array;
        	writeln (solve (n, a, b));
	}
}
