#include<stdio.h>

int main(void)
{
	int i,x[10000];
	
	for(i=0;i<=10000;i++){
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
	}
	for(i=0;i<=10000;i++){
		if(x[i]!=0){
			printf("Case %d: %d\n",i+1,x[i]);
		}else{
			break;
		}
	}
	return 0;
}
