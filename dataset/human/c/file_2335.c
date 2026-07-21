#include<stdio.h>
int main()
{
	long long m=1e9;
	int n,k,s;
	scanf("%d%d%d",&n,&k,&s);
	for(int i=0;i<n;i++)
	{
		if(i<k)
		{
			if(i==0)
			printf("%d",s);
			else 
			printf(" %d",s);
		}
		else 
		{
			if(s==m-1)
			printf(" %d",m);
			else 
			printf(" %d",m-1);
		}		
	}
	printf("\n");
	return 0;
}
