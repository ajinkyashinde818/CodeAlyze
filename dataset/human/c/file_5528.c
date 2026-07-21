#include <stdio.h>
#include <math.h>

int main(void) {
	_Bool flag[1000000] = {0};
	int n;
	long int total;
	int i,j;
	for (i = 2; i <= 3 || i <= sqrt(1000000); i++) {
		for (j = 2; i * j <= 1000000; j++) {
			flag[i*j-1] = 1;
		}
	}
	while (scanf("%d", &n)) {
		if (n == 0)
			break;
		total = 0;
		j = 1;
		for (i = 0; i < n; i++) {
			while (1) {
				j++;
				if (!flag[j-1]) {
					total += j;
					break;
				}
			}
		}
		printf("%ld\n", total);
	}
	return 0;
}
