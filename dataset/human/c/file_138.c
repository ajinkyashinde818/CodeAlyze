#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void) {
	int r, g, b, n;
	int  ans = 0;

	scanf("%d %d %d %d", &r, &g, &b, &n);

	for (int i = 0; i * r <= n; i++) {
		for (int j = 0; j * g <= n; j++) {
			//printf("i=%d  j=%d\n", i, j);
			if ((n - r * i - g * j) % b == 0 && n - r * i - g * j >= 0) {
			ans++;
			
			}
			//printf("n - r * i - g * j = %d\n", n - r * i - g * j);
			//printf("amari = %d\n", (n - r * i - g * j)%b);
		}
	}
	printf("%d", ans);
	return 0;
}
