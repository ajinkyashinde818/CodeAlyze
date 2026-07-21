#include <stdio.h>

int main(void)
{
	int k, s;
	scanf("%d %d", &k, &s);

	int i, j, t, count = 0;
	for(i = 0; i <= k; i++) {
		for(j = 0; j <= k; j++) {
			t = s - i - j;
			if(0 <= t && t <= k) {
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}
