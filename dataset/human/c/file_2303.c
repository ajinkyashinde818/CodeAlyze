#include <stdio.h>
int main()
{
	int n,k,s;
	scanf("%d %d %d",&n,&k,&s);
	for(int i=1;i<=n;i++)
	{
		if(k>0)
		printf("%d ",s);
		else
		if(s==1000000000)
		printf("1 ");
		else
		printf("%d ",s+1);
		k--;
	}
	return 0;
 }
