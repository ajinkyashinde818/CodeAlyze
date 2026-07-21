#include <stdio.h>

int main(void)
{
	int h, w;
	int i, j;
	
	scanf("%d %d", &h, &w);
	
	while (!(h == 0 && w == 0)){
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				if (i % 2 == 0){
					if (j % 2 == 0){
						printf("#");
					}
					else {
						printf(".");
					}
				}
				else {
					if (j % 2 == 0){
						printf(".");
					}
					else {
						printf("#");
					}
				}
			}
			printf("\n");
		}
		printf("\n");
		
		scanf("%d %d", &h, &w);
	}
	
	return (0);
}
