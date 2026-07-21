#include <stdio.h>
#include <string.h>

int main (int argc,char **argv)
{
	char x[2],y[2];
	int a = 0;

	scanf("%s %s",x,y);

	a = strcmp(x,y);
	if (a == 0)
	{
		printf("=\n");
	}

	else if (a < 0)
	{
		printf("<\n");
	}

	else
	{
		printf(">\n");
	}

	return 0;
}
