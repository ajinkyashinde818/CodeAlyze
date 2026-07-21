#include <stdio.h>
int n, k, c;
char s[200001];
int a[200000];
int b[200000];
int x, y;
int main() {
	scanf("%d%d%d", &n, &k, &c);
	scanf(" %s", s);
	x = -n - 1;
	for (int i = 0; i < n; i++) {
		if (x + c < i && s[i] == 'o') {
			x = i;
			a[i] = 1;
			y++;
		}
	}
	if (y > k)return 0;
	x = 2 * n;
	for (int i = n - 1; i >= 0; i--) {
		if (x - c > i && s[i] == 'o') {
			x = i;
			b[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] && b[i])printf("%d\n", i + 1);
	}
}
