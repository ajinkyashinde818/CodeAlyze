#include <stdio.h>

int main(void)
{
	int h, w, i1, i2;
	
	while (1){
		scanf("%d %d", &h, &w);
		
		if (h == 0 && w == 0){
			break;
		}
		
		else {
			for (i1 = 0; i1 < h; i1++){
				for (i2 = 0; i2 < w; i2++){
					if ((i2+i1) % 2 == 0){
						printf("#");
					}
					else {
						printf(".");
					}
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	
	return (0);
}
