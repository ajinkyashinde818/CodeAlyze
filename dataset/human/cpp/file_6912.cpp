#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int a[N], b[N], c[N];
int lb[N], rb[N];

int main () {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i ++)
		scanf("%d", b + i);

	for (int i = 1; i <= n; i ++)
		rb[a[i]] = i;
	for (int i = n; i >= 1; i --)
		lb[b[i]] = i;

	int sh = 0;
	for (int i = 1; i <= n; i ++) if (lb[i] && rb[i])
		sh = max(sh, rb[i] - lb[i] + 1);

	for (int i = 1; i <= n; i ++)
		c[(i + sh > n) ? (i + sh - n) : (i + sh)] = b[i];

	int ok = 1;
	for (int i = 1; i <= n; i ++) if (a[i] == c[i])
		ok = 0;

	if (ok) {
		puts("Yes");
		for (int i = 1; i <= n; i ++)
			printf("%d%c", c[i], "\n "[i != n]);
	} else {
		puts("No");
	}
}
