#include<stdio.h>

int main(void)
{
	int H[100], W[100];
	int i, j, k;
	int n = 0;
	
	while (1) {
		scanf("%d %d", &H[n], &W[n]);
		
		if (H[n] == 0 && W[n] == 0) {
			break;
		}
		
		n++;
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < H[i]; j++) {
			for (k = 0; k < W[i]; k++) {
				if (j % 2 == 1 && k % 2 == 1 || j % 2 == 0 && k % 2 == 0) {
					printf("#");
				}
				else {
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return (0);
}
