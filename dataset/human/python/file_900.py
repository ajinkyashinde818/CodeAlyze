import std.stdio;
import std.range;
import std.array;
import std.string;
import std.conv;
import std.typecons;
import std.algorithm;
import std.container;
import std.typecons;
import std.random;
import std.csv;
import std.regex;
import std.math;
import core.time;
import std.ascii;
import std.digest.sha;
import std.outbuffer;

void main() {
	auto args = readln.chomp.split;
	long n = args[0].to!int;
	long c = args[1].to!long;
	alias Node = Tuple!(long, "x", long, "v");
	Node[] nodes = new Node[](n);
	foreach (i; 0..n) {
		auto p = readln.chomp.split.map!(to!long);
		long x = p[0];
		long v= p[1];
		nodes[i] = Node(x, v);
	}
	std.algorithm.sort(nodes);
	// cw
	debug stderr.writeln("CW");
	long[] cw = new long[](n);
	long[] cwMax = new long[](n);
	{
		long v = 0;
		long x = 0;
		long ans = long.min;
		foreach (i, node; nodes) {
			long dx = node.x - x;
			x += dx;
			v -= dx;
			v += node.v;
			cw[i] = v;
			ans = max(ans, v);
			cwMax[i] = max(ans, v);
		}
	}
	debug stderr.writeln(cw, " ... ", cwMax);
	// ccw
	long[] ccw = new long[](n);
	long[] ccwMax = new long[](n);
	debug stderr.writeln("CCW");
	{
		long v = 0;
		long x = c;
		long ans = long.min;
		foreach_reverse(i, node; nodes) {
			auto j = n - 1 - i;
			long dx = x - node.x;
			x -= dx;
			v -= dx;
			v += node.v;
			ccw[j] = v;
			ans = max(ans, v);
			ccwMax[j] = ans;
		}
	}
	debug stderr.writeln(ccw, " ... ", ccwMax);
	// fast cw
	long ans = 0;
	for (int i = 0; i < n; ++i) {
		long v = cw[i];
		long w = long.min;
		if (n - 2 - i >= 0)
			w = max(0, v - nodes[i].x) + ccwMax[n - 2 - i];
		debug stderr.writefln("\t[%d] max(%d, %d)", i, v, w);
		ans = max(ans, v);
		ans = max(ans, w);
	}
	// fast ccw
	for (int i = 0; i < n; ++i) {
		long v = ccw[i];
		long w = long.min;
		if (n - 2 - i >= 0)
			w = max(0, v - (c - nodes[n - 1 - i].x)) + cwMax[n - 2 - i];
		debug stderr.writefln("\t[%d] max(%d, %d)", i, v, w);
		ans = max(ans, v);
		ans = max(ans, w);
	}
	ans.writeln;
}
