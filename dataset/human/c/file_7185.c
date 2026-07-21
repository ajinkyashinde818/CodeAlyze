#include<stdio.h>
int main(void) {
	int i, j, count , w, h;

	while (1) {
		
		scanf("%d %d", &h, &w);
		if (h == 0 && w == 0) {
			break;
		}
		for (i = 0;i < h;i++) {
			count=0;
			for (j = 0;j < w;j++) {
				if(i%2==0){
					if (count % 2 == 0) {
						printf("#");
					}
				
					else {
						printf(".");
					}
				}
				else{
					if (count % 2 == 0) {
						printf(".");
					}
				
					else {
						printf("#");
					}
				}
				count++;
			}
			count++;
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
