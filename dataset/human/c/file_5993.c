#include <stdio.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int main()
{
	int n, i;
	
	scanf ("%d", &n);
	
	int R[200000];
	
	for(i = 0; i < n; i++) {
		scanf ("%d", &R[i]);
	}
	
	int maxv = -2000000000;
	int minv = R[0];
	
	for (i = 1; i < n; i++) {
		maxv = max(maxv, R[i] - minv);
		minv = min(minv, R[i]);
	}
	
	printf ("%d\n", maxv);
	
	return 0;
}
