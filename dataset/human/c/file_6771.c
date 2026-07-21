#include <stdio.h>
#define N_MAX 200000
int main(int argc, char **argv) {
	int n, k;
	scanf("%i%i", &n, &k);
	int a[N_MAX + 1];
	for(int i = 1; i <= n; ++i) {
		scanf("%i", &a[i]);
	}
	int s = 1, t = 1000000000;
	while(s <= t) {
		int m = (s + t) / 2;
		int c = 0;
		for(int i = 1; i <= n; ++i) {
			c += (a[i] - 1) / m;
		}
		if(c > k) {
			s = m + 1;
		} else {
			t = m - 1;
		}
	}
	printf("%i\n", s);
	return 0;
}
