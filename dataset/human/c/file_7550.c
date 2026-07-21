#include <stdio.h>

int main(void)
{
		int x,n,i;
		int a[99999];
		i=0;
			scanf("%d",&x);
		while(x!=0){
			a[i]=x;
			i+=1;
			scanf("%d",&x);
		}
		for(n=0;n<=i-1;n++){
		printf("Case %d: %d\n",n+1,a[n]);
		}
	return 0;
}
