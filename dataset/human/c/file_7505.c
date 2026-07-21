#include <stdio.h>

int main(void)
{
	int x[10000],i,a=1;
	
	scanf("%d",&x[0]);
	while(x[a-1]!=0 ){
		scanf("%d",&x[a]);
		a++;
	}
	for(i=0 ; i<a-1 ; i++)
		printf("Case %d: %d\n",i+1,x[i]);
	
	return 0;
}
