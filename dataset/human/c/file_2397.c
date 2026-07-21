#include<stdio.h>
int main()
{
	char a[4];
	int i;
	int sum;
	scanf("%s", a);
	sum = 0;
	for (i = 0; i < 3; i++)
	{
		if (a[i] == 'a')sum = sum + 1;
		if (a[i] == 'b')sum = sum + 2;
		if (a[i] == 'a')sum = sum + 3;
	}
	if (sum == 6)printf("Yes");
	else printf("No");
	return 0;
}
