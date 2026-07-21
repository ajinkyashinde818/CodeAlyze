#include <stdio.h>
int main(void)
{
	int h, w, i, j;
	
	while(1)
	{
		scanf("%d %d", &h, &w);
		
		if(h ==0 && w == 0)
		{
			break;
		}
		
		else
		{
			for(i = 0; i < h; i++)
			{
				if(i % 2 == 0)
				{
					for(j = 0; j < w / 2; j++)
					{
						putchar('#');
						putchar('.');
					}
					if(w % 2 == 1)
					{
						putchar('#');
						putchar('\n');
					}
					else
					{
						putchar('\n');
					}
					
				}
				
				else
				{
					for(j = 0; j < w / 2; j++)
					{
						putchar('.');
						putchar('#');
					}
					if(w % 2 == 1)
					{
						putchar('.');
						putchar('\n');
					}
					else
					{
						putchar('\n');
					}
					
				}
			}
		}
		putchar('\n');
	}
	
	return 0;
}
