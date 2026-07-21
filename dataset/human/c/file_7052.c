#include<stdio.h>
int main()
{
	int h,w,x,y,amari;
	while(scanf("%d %d",&h,&w) && h!=0 || w!=0)
	{
		for(x=1; x<=h; x++)
		{
			for(y=1; y<=w; y++)
			{
				amari=x%2;
				if(amari==1)
				{
					amari=y%2;
					if(amari==1)
						printf("#");
					else
						printf(".");
				}
				else
				{
					amari=y%2;
					if(amari==1)
						printf(".");
					else
						printf("#");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
