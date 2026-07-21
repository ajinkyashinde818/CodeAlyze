#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>

int main()
{
	int n;
	int zoro;
	int d1,d2;

	zoro = 0;
	scanf("%d", &n);
	while (n)
	{
		scanf("%d %d", &d1,&d2);
		if (d1 == d2)
			zoro++;
		else
			zoro = 0;
		if (zoro == 3)
			break;
		n--;
	}
	if (zoro == 3)
		printf("Yes\n");
	else
		printf("No\n");
}
