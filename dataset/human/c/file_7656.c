#include<stdio.h>

#define N 10000

int main(void)
{
	int x[N],count=0,i;
	
	while(1){
		scanf("%d",&x[count]);
		count++;
		
		if(x[count-1]==0){
			break;
		}
	}
	
	for(i=0;i<count-1;i++){
		printf("Case %d: %d\n",i+1,x[i]);
	}
	
	return 0;
}
