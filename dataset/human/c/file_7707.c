#include <stdio.h>

int main(void){
	int i=0,num[10000]={},n;
	do{
		scanf("%d",&n);
		if(n!=0){
			num[i] = n;
			i++;
		}
	}while(n!=0);
	
	for(n=0;n<i;n++){
		printf("Case %d: %d\n",n+1,num[n]);
	}
	return 0;
}
