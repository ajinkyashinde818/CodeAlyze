import std.algorithm;
import std.array;
import std.range;
import std.stdio;
import std.string;

void main ()
{
	int n;
	int m;
multitest_loop:
	while (readf (" %s %s", &n, &m) > 0)
	{
		readln;
		bool [] [] a;
		foreach (row; 0..n)
		{
			a ~= readln.strip.map !(x => x == '#').array;
		}
		bool [] [] b;
		foreach (row; 0..m)
		{
			b ~= readln.strip.map !(x => x == '#').array;
		}
		foreach (row; 0..n - m + 1)
		{
			foreach (col; 0..n - m + 1)
			{
				if (equal (a.drop (row).take (m)
				    .map !(x => x.drop (col).take (m)), b))
				{
					writeln ("Yes");
					continue multitest_loop;
				}
			}
		}
		writeln ("No");
	}
}
