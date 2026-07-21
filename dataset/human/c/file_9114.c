#include <stdio.h>
int main()
{
	int a,b,sum,i,j;
	scanf("%d",&a);
	sum=0;
	scanf("%d\n",&i);
	for(j=1;j<=a;j++)
	{scanf("%d",&b);
		if(b>=i){
		sum=sum+1;}
		}
	printf("%d",sum);
	return 0;
	}
