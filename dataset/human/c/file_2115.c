#include<stdio.h>
#include<math.h>
long long modexp(long long n)
{
	long long  i=5;
	long long count=0;
	while(i<1000000000000000001)
	{
		count=count+(long long )n/i;
		i=i*5;
	}
	return count;
}


int main()
{
	long long n;

	scanf("%Ld",&n);
	if(n<=2)printf("0\n");
	else if(n%2==1)printf("0\n");
	else
	{
		printf("%Ld\n",modexp(n/2));
	}
	return 0;
}
