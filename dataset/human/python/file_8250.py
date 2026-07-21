import std.algorithm;
import std.array;
import std.conv;
import std.stdio;
import std.string;

void main ()
{
	int n;
multitest_loop:
	while (readf (" %s", &n) > 0)
	{
		readln;
		auto a = readln.split.map !(to !(int)).array;
		auto total = sum (a, 0L);
		auto once = n * 1L * (n + 1) / 2;
		if (total % once != 0)
		{
			writeln ("NO");
			continue multitest_loop;
		}
		auto num = total / once;
		long cur = 0;
		foreach (i; 0..n)
		{
			int j = (i + 1) % n;
			auto delta = a[j] - a[i];
			delta -= num;
			if (delta > 0 || delta % n != 0)
//			if (((a[j] - a[i]) % n + n) % n != num % n)
			{
				writeln ("NO");
				continue multitest_loop;
			}
			cur += -delta / n;
		}
		writeln (cur == num ? "YES" : "NO");
	}
}
