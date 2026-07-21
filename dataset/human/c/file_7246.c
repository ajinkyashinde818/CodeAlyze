#include<stdio.h>

int main(void)
{
	int H;
	int W;
	int i;
	int j;
	
	while(1){
		scanf("%d %d", &H, &W);
		
		if(H == 0 && W == 0){
			break;
		}
		for(i = 0;i < H;i++){
			if(i%2 == 0){
				for(j = 0;j < W;j++){
					if(j%2 == 0){
						printf("#");
					}
					else {
						printf(".");
					}
				}
			}
			else {
				for(j = 0;j < W;j++){
					if(j%2 == 0){
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
	}
	return (0);
}
