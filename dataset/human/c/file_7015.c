#include <stdio.h>

int main(void)
{
	int h, w;
	int i, f;
	
	while (1){
		scanf("%d %d", &h, &w);
		
		if (h == 0 && w == 0){
			break;
		}
		
		for (i = 0; i < h; i++){
			for (f = 0; f < w; f++){
				if ((i + f) % 2 == 0){
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
