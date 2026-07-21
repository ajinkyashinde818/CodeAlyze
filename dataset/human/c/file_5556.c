#include<stdio.h>
void solve(int n)
{
	long int c=0,f,j,s=0,i;
	for(i=2;;i++)
	{
		f=0;
		for(j=2;j*j<=i;j++)
			if(i%j==0)
			{
				f=1;
				break;
			}
		if(!f)
		{
			s+=i;
			if(++c>=n)
			{
				printf("%d\n",s);
				return;
			}
		}
	}
}

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		else
			solve(n);
	}
	return 0;
}
