#include <stdio.h>

int main(void)
{
	int i=0,n=1,a[10000];
	
	while(n!=0){
		scanf("%d",&n);
		a[i]=n;
		i=i+1;
	}
	for(n=0;n+1<i;n++){
		printf("Case %d: %d\n",n+1,a[n]);
	}
	return 0;
}
