import std.stdio, std.algorithm, std.range, std.conv, std.string, std.math;
import core.stdc.stdio;
// foreach, foreach_reverse, writeln

void main() {
	int n; long c;
	scanf("%d%ld", &n, &c);
	struct P { long x; int v;}
	P[] p = new P[n];
	foreach (i; 0..n) {
		long x; int v;
		scanf("%ld%d", &x, &v);
		p[i] = P(x,v);
	}
	long ans = 0;
	foreach (_; 0..2) {
		p.sort!("a.x<b.x");
		long[] l = new long[n+1];
		{
			long sum = 0, best = 0;
			foreach (i; 0..n) {
				sum += p[i].v;
				best = max(best, sum-p[i].x);
				l[i+1] = best;
			}
		}
		long[] r = new long[n+1];
		{
			long sum = 0, best = 0;
			foreach_reverse (i; 0..n) {
				sum += p[i].v;
				best = max(best, sum-(c-p[i].x)*2);
				r[i] = best;
			}
		}
		foreach (i; 0..n+1) {
			ans = max(ans, l[i]+r[i]);			
		}
		foreach (i; 0..n) {
			p[i].x = c-p[i].x;
		}
	}
	writeln(ans);
}
