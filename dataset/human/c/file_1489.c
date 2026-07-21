#include <stdio.h>
int main ()
{
	char x,y;
	int a,b;
	scanf("%c %c", &x, &y);
	{
		a = x;
        b = y; 
		if(a < b)
		{
			printf("<\n");
		}
		if(a > b)
		{
			printf(">\n");
		}
		if(a == b)
		{
			printf("=\n");
		}
	}
	return 0;
}
