#include <stdio.h>

int main()
{
	int n,k;
	int c = 0;

	scanf("%d", &n);
	scanf("%d", &k);
	int h[n];

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
		if (h[i] < k) {
			c++;
		}
	}
	printf("%d", n - c);
}
