#include<stdio.h>
#include<math.h>

unsigned long prime(int n) {
	int i,j,k,count=1;
	unsigned long sum = 2;
	for (i = 3; i <= 104729; i+=2) {
		k = 0;
		for (j = 3; j <= sqrt(i); j += 2) {
			if (i%j == 0) {
				k = 1;
				break;
			}
		}
		if (k == 0) {
			sum += i;
			count++;
			if (count == n)break;
		}
	}
	return sum;
}

int main(void)
{
	int n;

	for (;;) {
		scanf("%d",&n);
		if (n == 0)break;
		if (n == 1)
			printf("2\n");
		else
		printf("%lu\n",prime(n));
	}

	return 0;
}
