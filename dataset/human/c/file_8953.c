#include <stdio.h>

int main(void)
{
	int n, cnt;

	while (1) {
		cnt = 0;
		scanf("%d", &n);
		if (n == 0)
			break;
		while (1) {
			if (n == 1)
				break;
			else if (n % 2 == 0) {
				n /= 2;
				cnt++;
			} else {
				n = n * 3 + 1;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
