#include<stdio.h>
int main()
{
	int n, k, c;
	scanf("%d %d %d", &n, &k, &c);
	char s[200005];
	scanf("%s", s);
	int i, j;
	int l[200005], r[200005];
	j = 0;
	for (i = 0;j < k; j++)
	{
		while (s[i] == 'x')
			i++;
		l[j] = i;
		i += c + 1;
	}
	j = k - 1;
	for (i = n - 1; j >= 0; j--)
	{
		while (s[i] == 'x')
			i--;
		r[j] = i;
		i -= c + 1;
	}
	for (i = 0; i < k; i++)
		if (l[i] == r[i])
			printf("%d\n", l[i] + 1);
	return 0;
}
