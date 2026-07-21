#include<stdio.h>
int main(void)
{
	long long int a = 0, b = 0;
	scanf("%lld%lld", &a, &b);

	if (a < b) {
		long long int count1 = a;
		while (1) {
			count1 += a;
			if (count1 % b == 0) {
				break;
			}
		}

		printf("%lld\n", count1);
	}
	else {
	    long long int count2 = 0;
		while (1) {
			count2 += b;

			if (count2 % a == 0) {
				break;
			}
		}

		printf("%lld\n", count2);
	}

	return 0;
}
