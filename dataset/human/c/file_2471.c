#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[4];
	scanf("%s", str);
	if (strcmp(str,"abc")==0|| strcmp(str, "acb") == 0 || strcmp(str, "bac") == 0 || strcmp(str, "bca") == 0 || strcmp(str, "cab") == 0 || strcmp(str, "cba") == 0)
	{
		printf("Yes\n");
	}
	else printf("No\n");
	return 0;
}
