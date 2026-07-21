#include<stdio.h>
#include<string.h>
int main()
{
	char s[500005];
	scanf("%s", s);
	int i, l, r, n = strlen(s);
	l = 200005;
	for (i = 0; i < n; i++)
		s[l + i] = s[i];
	r = n + l;
	l--;
	int q;
	scanf("%d", &q);
	int t, f;
	char c;
	int p = 0;
	for (i = 0; i < q; i++)
	{
		scanf("%d", &t);
		if (t == 1)
			p ^= 1;
		else
		{
			scanf("%d %c", &f, &c);
			if (f == 1)
			{
				if (p == 0)
				{
					s[l] = c;
					l--;
				}
				else
				{
					s[r] = c;
					r++;
				}
			}
			else
			{
				if (p == 0)
				{
					s[r] = c;
					r++;
				}
				else
				{
					s[l] = c;
					l--;
				}
			}
		}
	}
	if (p == 0)
	{
		for (i = l + 1; i < r; i++)
			printf("%c", s[i]);
	}
	else
	{
		for (i = r - 1; i > l; i--)
			printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}
