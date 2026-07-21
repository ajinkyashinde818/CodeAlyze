#include <stdio.h>

int main(void)
{
	int i = 1;
	int num[10000];
	int j = 0;
	int n;
	
	while(i != 0){
		scanf("%d",&i);
		if(i != 0){	
			num[j] = i;
			j++;
		}
	}
	for(n = 0;n < j;n++){
		printf("Case %d: %d\n",n+1,num[n]);
	}
	
	return(0);
}
