#include<stdio.h>
int main(void)
{
	int a,b,c=0,i,j,k;
	while(c==0)
	{
		scanf("%d %d",&a,&b);
		if(a==0&&b==0)
		{
			c=1;
			break;
		}
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				if((i+j)%2==0)printf("#");
				if((i+j)%2==1)printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
