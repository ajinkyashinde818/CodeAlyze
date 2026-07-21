#include<stdio.h>
int main(void)
{
	int k,s,a=0,i,j,l;
	scanf("%d %d", &k, &s);
	for(i=0; i<=k; i++)
	{
		for(j=0; j<=k; j++)
		{
			if(i+j<=s&&s-i-j<=k)
			a++;
		}
	}
	printf("%d\n", a);
	
	return 0;
}
