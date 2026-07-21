#include <stdio.h>
int main(void)
{
	int h,w;
	int height,width;
	while(1)
	{
		scanf("%d %d", &height, &width);
		if(height==0 && width==0)
			break;
		for(h=0; h<height; h++)
		{
			for(w=0; w<width; w++)
			{
				if((w+h)%2==0)
					 printf("#");
				else printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
