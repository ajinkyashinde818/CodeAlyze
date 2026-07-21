import std.stdio;

void main() {
	int n, k, s;
	scanf("%d %d %d\n", &n, &k, &s);
	if (s == 10^^9) {
		foreach(_;0..n-k) {
			write(1, " ");
		}
		foreach(_;0..k) {
			write(10^^9, " ");
		}
	}
	else {
		foreach(_;0..n-k) {
			write(s+1, " ");
		}
		foreach(_;0..k) {
			write(s, " ");
		}
	}
}
