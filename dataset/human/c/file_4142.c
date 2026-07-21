#include<stdio.h>
int main (void)
{
	int a,b,c,i,k,tmp=2;
	int p[256],j=1;
	scanf("%d %d %d",&a,&b,&k);
	c=a;
	p[0]=1;
	if(a>b)
	{
		c=b;
	}
	
	for(i=2;i<=c;i++){
	if(a%i==0&&b%i==0)
	{
		p[j]=i;
		tmp++;
		j++;
	}
}

printf("%d",p[j-k]);
return 0;
}
