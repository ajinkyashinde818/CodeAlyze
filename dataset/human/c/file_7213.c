#include <stdio.h>

int main(void)
{
	int a,b,i,j;
	scanf("%d %d",&a ,&b);
	while(a != 0 || b != 0){
		for(i = 0; i < a; i++){
			for(j = 0;j < b; j++){
				if( (0 == (i % 2) && 0 == (j % 2)) || (1 == (i % 2) && 1 == (j % 2)) ){
					printf("#");
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
		scanf("%d %d",&a ,&b);
		printf("\n");
	}
		
return 0;
}
