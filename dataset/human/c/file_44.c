#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
	int r, g, b, n;
	int i, j, k;
	int sum = 0;
	
	
	scanf("%d%d%d%d", &r, &g, &b, &n);
	
	for(i = 0; i <= n / r; i++) {
		for(j = 0; j <= n / g; j++) {
			if(i * r + j * g > n) {
				break;
			}
			if( (n - r * i - g * j) % b != 0) {
				continue;
			}
			sum++;
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}
