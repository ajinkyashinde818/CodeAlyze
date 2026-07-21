#include<stdio.h>

int main(void)
{
	int H,W;
	int i,j,k;
	
	while(1)
	{
	   scanf("%d%d",&H,&W);
	   if(H==0 && W==0) break;
	   k=0;
	   for(i=1;i<=H;i++)
	   {
	   	for(j=1;j<=W;j++)
		{
			if(k%2==0)
			{
			   printf("#");
			}
			else
			{
				printf(".");
			}
			k++;
		}
		if(W%2==0)
		{
			k++;
		}
		printf("\n");
	   }
	   printf("\n");
	}
	return 0;
}
