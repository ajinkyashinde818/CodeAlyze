#include <stdio.h>

int mystlen(char str[]);

int main(void)
{
	int x[10000], i, j=0;
	
	scanf("%d", &x[0]);
	
	while (x[j] != 0) {
		j++;
		
		if (j == 10000) {
			break;
		}
		scanf("%d", &x[j]);
	}
	for (i=1; i<=j; i++) {
				printf("Case %d: %d\n", i, x[i-1]);
	}
	return 0;
}
