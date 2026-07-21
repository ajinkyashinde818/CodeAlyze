#include<stdio.h>
int main(void)
{
	int a,b,c,d,s,k;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	s=a*b;
	k=c*d;
	if(s>k)	{
		printf("%d\n",s);
	}
	else	{
		printf("%d\n",k);
	}
	return 0;
}
