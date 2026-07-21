import std.stdio, std.algorithm, std.range, std.conv, std.string;
import core.stdc.stdio;
// foreach, foreach_reverse, writeln

void main() {
	int n;
	scanf("%d", &n);
	int[] a = new int[n];
	int[] b = new int[n];
	foreach (i; 0..n) scanf("%d", &a[i]);
	foreach (i; 0..n) scanf("%d", &b[i]);
	int ans = 0;
	foreach (k; 0..29) {
		int mask = (1<<k)-1;
		int s = 0;
		if (n&1) {
			foreach (x; a) s ^= x>>k&1;
			foreach (x; b) s ^= x>>k&1;
		}
		int[] c = new int[n];
		c[] = b[]&mask;
		sort(c);
		auto sorted = assumeSorted(c);
		foreach (x; a) {
			x &= mask;
			int l = n - to!int(sorted.lowerBound((1<<k)-x).length);
			s ^= l&1;
		}
		ans |= s<<k;
	}
	writeln(ans);
}
