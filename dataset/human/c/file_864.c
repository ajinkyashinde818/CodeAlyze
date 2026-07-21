#include<stdio.h>
#include<math.h>

int main(void)
{
	unsigned long long int a, b, c = 1, i, j, sq;
	long long int ret = 0;

	
	scanf("%lld", &a);

	sq = sqrt(a);

	for (i = 2; i <= sq; i++) {
		if (a % i == 0) {
			c = 1;
			while (1) {
				b = 0;
				for (j = 0; j < c; j++) {
					if (a % i != 0) {
						b = 1;
						break;
					}
					a = a / i;
				}

				if (b == 1) {
					break;
				}

				ret++;
				c++;
			}
			sq = sqrt(a) + 1;
		}
	}

	if (a != 1) {
		(ret)++;
	}

	printf("%d", ret);

	return 0;
}
