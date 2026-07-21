#include<stdio.h>
main()
{
	int H = 0, W = 0, i = 0, j = 0;
	
	scanf("%d %d", &H, &W);
	
	while(((1 <= H) && (1 <= W)) && ((H <= 300) && (W <= 300)))
	{
		for(i = 0; i < H; i++)
		{
			for(j = 0; j < W; j++)
			{
				if((i % 2 == 0) && (j % 2 == 0))
				{
					printf("#");
				}
				else if((i % 2 == 0) && (j % 2 == 1))
				{
					printf(".");
				}
				else if((i % 2 == 1) && (j % 2 == 0))
				{
					printf(".");
				}
				else if((i % 2 == 1) && (j % 2 == 1))
				{
					printf("#");
				}
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d %d", &H, &W);
	}
	return 0;
}
