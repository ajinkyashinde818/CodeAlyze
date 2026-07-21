import std.stdio;
import std.conv;
import std.string;
import std.typecons;
import std.algorithm;
import std.array;
import std.range;
import std.math;
import std.container;
import std.datetime;

void main()
{
	auto c = [4, 1, 4, 1, 2, 1, 2, 1];

	foreach (line; stdin.byLine) {
		auto num = int.max;
		auto ev = int.max;
		auto res = c;

		auto x = line.chomp.split().map!(to!int).array;
		foreach (i; 0..8) {
			int sum;
			foreach (j; 0..8) {
				sum += max(x[j] - c[(i+j) % 8], 0);
			}

			if (sum < num) {
				num = sum;
				ev = (c[i..$] ~ c[0..i]).map!(to!string).join("").to!int;
				res = (c[i..$] ~ c[0..i]);
			} else if (sum == num) {
				if ( ev > (c[i..$] ~ c[0..i]).map!(to!string).join("").to!int) {
					ev = (c[i..$] ~ c[0..i]).map!(to!string).join("").to!int;
					res = (c[i..$] ~ c[0..i]);
				}
			}
		}
		res.map!(to!string).join(" ").writeln;
	}
}
