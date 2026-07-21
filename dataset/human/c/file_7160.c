#include <stdio.h>

int main(void)
{
	int h, w;
	int i, j;
	
	while (h != 0 || w != 0){
		scanf("%d %d", &h, &w);
		for (i = 0; i < h; i++){
			if ((i + 1) % 2 == 1){
				for (j = 0; j < w; j++){
					if ((j + 1) % 2 == 1){
						printf("#");
					}
					else if (j != w){
						printf(".");
					}
					else {
						printf(".\n");
					}
				}
			}
			else {
				for (j = 0; j < w; j++){
					if ((j + 1) % 2 == 0){
						printf("#");
					}
					else if (j != w){
						printf(".");
					}
					else {
						printf(".\n");
					}
				}
			}
			printf("\n");
		}
		if (h != 0 || w != 0){
			printf("\n");
		}
	}
	
	return (0);
}
