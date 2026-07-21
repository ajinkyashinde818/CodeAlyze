#include<stdio.h>
int main(void){
	int i=0,x[10000];
	do{
		scanf("%d",&x[i]);
		i++;
	}while(x[i-1]!=0);
	for(i=0;x[i]!=0;i++){
		printf("Case %d: %d\n",i+1,x[i]);
	}
	return 0;
}
