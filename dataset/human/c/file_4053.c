#include <stdio.h>

int main(void)
{

	int a,b,k,tmp,i,n;

	n=0;

	scanf("%d%d%d",&a,&b,&k);

	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}

	for(i=a; i>=1; i--)
	{
		if((b%i==0)&&(a%i==0)) n=n+1;
		if(n==k)
		{
			printf("%d",i);
			break;
		}
	}

	return 0;
}
