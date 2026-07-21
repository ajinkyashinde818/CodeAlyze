#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int N, K;
	char s[11];
	scanf("%d", &N);
	scanf("%s", s);
	scanf("%d", &K);
	int i;
	char check = s[K - 1];
	for (i = 0;i < N;i++)
	{
		if (s[i] != check)s[i] = '*';
	}
	printf("%s\n", s);
	return 0;
}
