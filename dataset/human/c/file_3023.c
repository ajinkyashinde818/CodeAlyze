#include <stdio.h>

int k, n, a[200200];

int main()
{
	scanf ("%d %d", &k, &n);
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
	int mx = k + a[0] - a[n-1];
	for (int i = 1; i < n; i++){
		int d = a[i] - a[i - 1];
		if (mx < d)
			mx = d;
	}
	printf ("%d\n", k - mx);

	return 0;
}
