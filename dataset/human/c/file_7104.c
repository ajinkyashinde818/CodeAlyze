#include <stdio.h>

int main(void){
	int num1,num2;
	int i,j;
	scanf("%d %d",&num1,&num2);
	while(num1 + num2 != 0){
		for(i = 0;i < num1;i++){
			for(j = 0;j < num2;j++){
				if(i%2 == j%2) printf("#");
				else printf(".");
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d %d",&num1,&num2);
	}
	return 0;
}
