#include <stdio.h>

int main(void)
{
	int x,i,a[10000],b;
	
	x = 1;
	i = 0;
	
	while(x != 0){
		scanf("%d",&x);
		a[i] = x;
		++i;
	}
	
	for(b = 0;b < i-1;++b){
		printf("Case %d: %d\n",b+1,a[b]);
	}
	
	return(0);
}
