#include <stdio.h>

int main(void)
{
	int h, w;
	int i, j;
	
	while (h != 0 || w != 0){
		scanf("%d %d", &h, &w);
		if (h == 0 && w == 0){
			break;
		}
		
		for (i = 0; i < h; i++){
			for (j = i; j < w + i; j++){
				if (j % 2 == 0){
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
