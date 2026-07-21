import std.algorithm;
import std.array;
import std.conv;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

int solve (int a, int b, int c)
{
	int res = 0;
	int pairs = min (a, c);
	c -= pairs;
	a -= pairs;
	res += pairs;
	int goods = min (b, c);
	c -= goods;
	b -= goods;
	res += goods * 2;
	res += b;
	if (c > 0)
	{
		res += 1;
	}
	return res;
}

void main ()
{
	int a, b, c;
	while (readf (" %s %s %s", &a, &b, &c) > 0)
	{
		writeln (solve (a, b, c));
	}
}
