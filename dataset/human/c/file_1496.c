#include<stdio.h>
#include<string.h>
int main()
{
	char x,y,c;
	while(~scanf("%c %c%c",&x,&y,&c))
	{
			x = x-55;
			y = y-55;
			if(x==y)
			{
				printf("=\n");
				}
				else if(x<y)
				{
					printf("<\n");
					}
					else if(x>y)
					{
						printf(">\n");
					}	
		}
		return 0;
	}
