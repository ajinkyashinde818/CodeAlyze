#include<stdio.h>
int main()
{
	int k,s,i,j,l,n;
	scanf("%d%d",&k,&s);
	n=0;
	for(i=0;i<=k;i++)
	{
		for(j=0;j<=k;j++)
		{
		    l=s-i-j;
		    if(l<=k&&l>=0) n+=1;
		}
	}
	printf("%d",n);
	return 0;
}
