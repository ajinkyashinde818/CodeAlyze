#include<stdio.h>
int commonfactor(int a ,int b)
{
	if(a%b==0)
	  return b;
	return commonfactor(b,a%b);
}
int main()
{
	int a,b,k;
	scanf("%d %d %d",&a,&b,&k);
	int n=1;
	int cf;
	int bcf;
	bcf=commonfactor(a,b);
	cf=bcf;
	int i;
	for(i=2;i<=bcf;i++)
	{
		if(n!=k)
		{
			if(bcf%i==0)
			{
				cf=bcf/i;
				n++;
			}
		}
	}
	printf("%d",cf);
}
