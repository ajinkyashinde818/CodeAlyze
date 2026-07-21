#include<stdio.h>
int a[300];
int main()
{
	int i,n,d,x,choc=0,dt;
	while(scanf("%d%d%d",&n,&d,&x)==3)
	{
		choc=x+n;
		for( i=0;i<n;i++)
		scanf("%d",&a[i]);
		for( i=0;i<n;i++)
			choc+=(int)((d-1)/a[i]);
	    printf("%d\n",choc);
	}
	return 0;
}
