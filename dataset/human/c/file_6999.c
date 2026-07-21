#include <stdio.h>

int main(){
	int i,j;
	int a,b;
	while(1){
		scanf("%d %d",&a,&b);
		if(a==0&&b==0){
			break;
		}
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				if((i+j)%2){
					printf(".");
				}else{
					printf("#");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
