#include<stdio.h>
int main()
{
	int a,b[10000],i=0;
	while(scanf("%d",&a)!=EOF)
	{
		if(a==0) break;
		i++;
		b[i]=a;
	}
	for(int k=1;k<=i;k++)
		printf("Case %d: %d\n",k,b[k]);
	return 0;
}
