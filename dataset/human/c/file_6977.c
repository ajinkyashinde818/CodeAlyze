#include <stdio.h>

int main(void)
{
	int h, w;
	int i, j;
	
	while (scanf("%d %d", &h, &w) != EOF){
		if (h == 0 && w == 0) break;
		
		for (i = 1; i <= h; i++){
			for (j = 1; j <= w; j++){
				if ((i + j) % 2 == 0){
					printf("#");
				}
				else{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return (0);
}
