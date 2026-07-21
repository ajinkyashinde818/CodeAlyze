#include<stdio.h>
#include<string.h>
int main()
{
	char s[100005];
	scanf("%s", s);
	int n = strlen(s);
	int ans = 0; 
	int i, j;
	i = 0; j = n - 1;
	while (i < j)
	{
		if (s[i] == s[j])
		{
			i++;
			j--;
		}
		else
		{
			ans++;
			if (s[i] != 'x' && s[j] != 'x')
			{
				printf("-1\n");
				return 0;
			}
			if (s[i] == 'x')
				i++;
			else
				j--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
