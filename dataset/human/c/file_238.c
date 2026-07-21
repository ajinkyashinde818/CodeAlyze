#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	
	int n;
	unsigned long int ans = 0;
	unsigned long int min = 1000000000;
	long int kou_max;
	long int a[100000];
	long int i, j, k;
	int flg;
	int minus = 0;
	int count_zero = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
		ans += abs(a[i]);
		if(a[i] < 0) {
			minus++;
		}
		if(min > abs(a[i])) {
			min = abs(a[i]);
		}
	}
	
	if(minus % 2 != 0) {
		ans -= (2 * min);
	}
	printf("%ld", ans);
	
	return 0;
}
