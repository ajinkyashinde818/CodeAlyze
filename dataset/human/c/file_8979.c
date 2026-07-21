#include <stdio.h>
int main() {
	int n, count;
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		for(count = 0; n != 1; ++ count) {
			if(n % 2 == 0) n /= 2;
			else n = 3 * n + 1;
		}
		printf("%d\n", count);
	}
	return 0;
}
