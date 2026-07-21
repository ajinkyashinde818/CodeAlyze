#include <stdio.h>
int n, itr, x, a[100005], v[100005];
int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", a + i);
	x = 1;
	while (1) {
		if (x == 2) {
			printf ("%d\n", itr);
			return 0;
		}
		if (v[x]) {
			puts ("-1");
			return 0;
		}
		v[x] = 1;
		x = a[x], itr++;
	}
	return 0;
}
