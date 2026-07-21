#include <stdio.h>

int main(void)
{
	int w, h;
	int i, n;
	
	while (1){
		scanf("%d %d", &h, &w);
		
		if (w == 0 && h == 0){
			break;
		}
		
		for (i = 0; i < h; i++){
			for (n = 0; n < w; n++){
				
				if (i % 2 == 0){
					if (n % 2 == 0){
						printf("#");
					}
					else{
						printf(".");
					}
				}
				
				else{
					if (n % 2 == 0){
						printf(".");
					}
					else{
						printf("#");
					}
				}
				
			}
			printf("\n");
		}
		printf("\n");
	}
	return (0);
}
