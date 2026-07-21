#include <stdio.h>

int main(){

	int a=-1,b,i,j;
	while(1){
		scanf("%d %d",&a,&b);
		if(a==0&&b==0)
			break;

		for(i=0;i<a;i++){
			for(j=0;j<b;j++)
				if((i+j)%2==0)
					printf("#");
				else
					printf(".");
			printf("\n");
		}
		printf("\n");
		
	}
	//for(i=0;i<=1000000000;i++);
	return 0;
}
