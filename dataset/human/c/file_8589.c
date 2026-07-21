#include <stdio.h>
int n, x, c;
int a[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		c++;
		if (a[x] != 1) {
			x = a[x];
		}
		else break;
	}
	if (c != n)printf("%d\n", c);
	else printf("-1\n");
}
