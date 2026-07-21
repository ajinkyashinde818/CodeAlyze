#include<stdio.h>
int main(void) {
	unsigned int n,count;

	while (1) {
		scanf("%lu",&n);
		if (n == 0)break;
		count = 0;
		while (n != 1) {
			if (n % 2 == 0) {
				n /= 2;
				count++;
			}
			else {
				n = n * 3 + 1;
				count++;
			}
		}
		printf("%lu\n",count);
	}
	return 0;
}
