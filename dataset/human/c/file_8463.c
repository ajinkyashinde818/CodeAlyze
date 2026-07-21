#include <stdio.h>
#define N_MAX 100

int a[N_MAX];

int n, m;
int i;

int main(void){
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	for (i = 1; i <= m; i++) {
		int j;
		for (j = 0; j + 1 < n; j++) {
			if (a[j] % i > a[j+1] % i) {
				a[j+1] ^= a[j];
				a[j] ^= a[j+1];
				a[j+1] ^= a[j];
			}
		}
	}

	for (i = 0; i < n; i++) printf("%d\n", a[i]);

	return 0;
}
