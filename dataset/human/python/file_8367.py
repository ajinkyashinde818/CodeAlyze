import std.stdio;

void main() {
	int k, n;
	readf(" %s %s", &k, &n);

	auto a = new int[n];

	foreach (ref e;a) {
		readf(" %s", &e);
	}

	int max = 0;

	foreach (i;0..a.length - 1) {
		auto d = a[i + 1] - a[i];
		if (d > max) {
			max = d;
		}
	}
	auto d = k - a[$ - 1] + a[0];
	if (d > max) {
		max = d;
	}

	writeln(k - max);
}
