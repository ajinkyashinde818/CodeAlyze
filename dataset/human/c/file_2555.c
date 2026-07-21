#include<stdio.h>
int main()
{
	char str[5];
	while(gets(str)!=NULL)
	{
		if((str[0]!=str[1])&&(str[1]!=str[2])&&(str[2]!=str[0]))
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}
