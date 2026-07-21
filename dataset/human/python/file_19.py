import std.stdio;

void main() {
	int r,g,b,n;
	scanf("%d %d %d %d", &r, &g, &b, &n);
	size_t total;
	for (int i; i <= n; i += r) {
		for (int j = i; j <= n; j += g) {
			if ((n - j) % b == 0) ++total;
		}
	}
	total.write;
}
