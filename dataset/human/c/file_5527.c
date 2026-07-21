#include <stdio.h>
#define MAX_NUM (104730)

void enum_prime(char list[]) {
	int i, j;

	list[0] = list[1] = 0;
	for (i = 2; i < MAX_NUM; i++) {
		list[i] = 1;
	}
	for (i = 2; i < MAX_NUM; i++) {
		if (list[i] == 0)
			continue;
		for (j = i + i; j < MAX_NUM; j += i) {
			list[j] = 0;
		}
		if (MAX_NUM < i * i)
			break;
	}
}

int main() {
	int i, n, sum;
	char prime_list[MAX_NUM];

	enum_prime(prime_list);
	while (1) {
		scanf("%d ", &n);
		if (n == 0) {
			break;
		}
		sum = 0;
		for (i = 0; i < MAX_NUM; i++) {
			if (prime_list[i]) {
				sum += i;
				--n;
				if (n == 0) {
					break;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
