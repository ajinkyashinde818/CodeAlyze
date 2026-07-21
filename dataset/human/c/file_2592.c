#include <math.h>
#include<stdio.h>
int main()
{
	char a[4];
	gets(a);
	int i=0, j=0, k=0;
	for (int n = 0; n < 4; n++)
	{
		switch (a[n])
		{
		case 'a':i++; break;
		case 'b':j++; break;
		case 'c':k++; break;
		}
	}
	if (i&&j&&k)
		printf("Yes");
	else
		printf("No");
	return 0;
}
