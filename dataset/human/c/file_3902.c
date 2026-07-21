#include<stdio.h>
int min(int a,int b)
{
	if(a>b) return b;
	else    return a;
}
int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		int ans[999];
		int m=0;
		for(int i=1;i<=min(a,b);i++)
		{
			if(a%i==0&&b%i==0) ans[m++]=i;
		}
		printf("%d\n",ans[m-c]);
	}
	return 0;
}
