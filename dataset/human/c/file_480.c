#include <stdio.h>
int main()
{
	long a, i, x;
	long sum = 0;
	long sumn = 0;
	long min = 2000000001;
	long c[200000];
	scanf("%ld",&a);
	for (i = 0; i < a; i++) {
		scanf("%ld",&c[i]);
		sum += c[i];
	}
	for (i = 0; i < a-1; i++) {
			sumn += c[i];
		if (sum - sumn*2 > 0) {
			x = sum - sumn*2;
		}
		else {
			x = sumn*2 - sum;
		}
		if (x < min) {
			min = x;
		}
	}
    printf("%ld", min);
	return 0;
}
