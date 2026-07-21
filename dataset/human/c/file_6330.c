#include <stdio.h>
#include <limits.h>
int main(void)
{
	int i, n;
	scanf("%d", &n);
	int a[n];
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	int maxv = INT_MIN;
	int min = a[0];
	
	for(i = 1; i < n; i++){
		if(maxv < a[i]-min)maxv = a[i] - min;
		if(min > a[i]) min = a[i];
	}
	
	printf("%d\n", maxv);
	
	return 0;
}
