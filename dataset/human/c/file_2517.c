#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[4];
	int i;
	int j=3;
	char c;
 
	gets(s);
 
	for (c= 97; c< 100; c++)
	{
		for (i = 0; s[i]!= 0; i++)
		{
			if (c == s[i])
			{
	             j--;
				 break;
			}
			
		}
	}
	if (j == 0)
		printf("Yes");
	else
		printf("No");
 
    return 0;
}
