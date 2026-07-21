#include <stdio.h>

int main(void)
{
	int value_1, value_2,i,k;
	scanf("%d %d",&value_1,&value_2);

	while(value_1 != 0 && value_2 != 0)
	{
		for(i=0 ;i<value_1 ;i++)
		{
			for(k=0 ;k<value_2 ;k++)
			{
				//偶数判定
				if((i % 2) == 0)
				{
					if((k % 2) == 0)
					{
						printf("#");
					}
					else
					{
						printf(".");
					}
				}
				else
				{
					if((k % 2) == 0)
					{
						printf(".");
					}
					else
					{
						printf("#");
					}
				}
			}
			printf("\n");
		}

		printf("\n");
		scanf("%d %d",&value_1,&value_2);
	}
	return 0;
}
