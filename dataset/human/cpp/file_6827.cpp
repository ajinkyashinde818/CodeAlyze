#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int n, a[N], b[N], t, l, r;

inline void solve() {
	for (register int i = 0; i < n; i++)
		if (a[i] == b[i]) {
			l = i;
			t = a[i];
			break;
		}
	for (register int i = n-1; i >= 0; i--)
		if (a[i] == t && b[i] == t) {
			r = i;
			break;
		}
	for (register int i = 0; i < n; i++)
		if (a[i] != t && b[i] != t && l <= r)
			swap(b[i], b[l++]);
	if (l <= r) {
		puts("No");
		return;
	}
	puts("Yes");
	for (register int i = 0; i < n; i++)
		printf("%d ", b[i]);
	puts("");
}

int main() {
	scanf("%d", &n);
	for (register int i = 0; i < n; i++)
		scanf("%d", a+i);
	for (register int i = n-1; i >= 0; i--)
		scanf("%d", b+i);
	solve();
	return 0;
}
