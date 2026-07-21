#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
	int n, d, x, a[100], ans = 0;
	scanf("%d %d", &n, &d);
	scanf("%d", &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		ans += (d + a[i] - 1) / a[i];
	}
	printf("%d\n", ans + x);
}
