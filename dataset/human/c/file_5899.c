#include<stdio.h>
int main(void)
{
	int n,m,l,i,d=-1000000000;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d",&l);
		if(d<l-m)d=l-m;
		if(l<m)m=l;
	}
	printf("%d\n",d);
	return 0;
}
