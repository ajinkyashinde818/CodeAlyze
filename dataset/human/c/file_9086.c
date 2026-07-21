#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)

typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);

	for (size_t i = 0; i < n; i++)
	{
		int h;
		scanf("%d", &h);
		if (h >= k)
		{
			cnt++;
		}
	}

	printf("%d", cnt);
}
