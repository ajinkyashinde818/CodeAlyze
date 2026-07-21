#include <stdio.h>


int main()
{
	int R[200000];
	int maxv, minv;
	int i, j, n;
	
	scanf("%d",&n);
	
	for (i = 0; i < n; i++) {
		scanf("%d",&R[i]);
	}
	
	minv = R[0];
	maxv = R[1] - R[0];
	
	
	
	for (j = 1; j <= n - 1; j++) {
		if (maxv < R[j] - minv) {
			maxv = R[j] - minv;
		}
		if (R[j] < minv) {
			minv = R[j];
		}
	}
		
	printf("%d\n",maxv);
return 0;
}
