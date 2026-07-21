#include <stdio.h>
int main()
{
	int a;
	scanf("%d\n",&a);
	int c[60],b,sum,sum1,sum2,i[60],j[60];
	sum=0;
	sum1=0;
	for(b=0;b<a;b++)
	{
		scanf("%d",&i[b]);
	}
	for(b=0;b<a;b++)
	{scanf("%d",&c[b]);
	sum=sum+c[b];	
	}
	for(b=0;b<a-1;b++){
		
		scanf("%d",&j[b]);
	}for(b=0;b<a;b++)
	{
		if(i[b]-i[b-1]==1&&i[b]!=1){
		sum1=sum1+j[i[b]-2];}
	}
	sum2=sum1+sum;
	printf("%d",sum2);
	return 0;
	}
