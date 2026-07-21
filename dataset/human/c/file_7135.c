#include<stdio.h>

int main(void)
{
	int i,o,k,l;
	while(1)
	{
		scanf("%d %d",&i,&k);
		if(i == 0 && k == 0)
		{
			break;
		}
		for(o = 0;o < i;o++)
		{
			for(l = 0;l < k;l++)
			{
					if((o + l) % 2 == 0)
					{
						printf("#");
					}
					else
					{
						printf(".");
					}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}
