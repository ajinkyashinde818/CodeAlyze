#include<stdio.h>
#include<string.h>

int main()
{
	char s[100], t[100];
	scanf("%s", s);
	scanf("%s", t);
	int i,j;
	char tmp;
	for ( i = 0; i < strlen(s); i++)
	{
		for ( j = i+1; j < strlen(s); j++)
		{
			if (s[i] > s[j])
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
	for (i = 0; i < strlen(t); i++)
	{
		for (j = i + 1; j < strlen(t); j++)
		{
			if (t[i] < t[j])
			{
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
	for (i = 0; i < strlen(s) && i < strlen(t); i++)
	{
		if (s[i]<t[i])
		{
			printf("Yes");
			return 0;
		}
		else if (s[i] > t[i])
		{
			printf("No");
			return 0;
		}
	}
	if (i == strlen(s) && i < strlen(t))
		printf("Yes");
	else
		printf("No");
	return 0;
}
