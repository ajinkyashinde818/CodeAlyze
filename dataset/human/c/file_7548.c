#include "stdio.h"
int main(void)
{
	int num[10000],tmp,i;
	for(i=0;;i++){
		scanf("%d",&num[i]);
		if(num[i]==0){
			tmp=i;
			break;
		}
	}
	for(i=0;i<tmp;i++){
		printf("Case %d: %d\n",i+1,num[i] );
	}
	return 0;
	
}
