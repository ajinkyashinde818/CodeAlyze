#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i, n, x, min, max = INT_MIN;
	
	scanf("%d", &n);
	scanf("%d", &min);
	for(i = 1; i < n; i++){
		scanf("%d", &x);
		if(max < x - min) max = x - min;
		if(x < min) min = x;
	}
	printf("%d\n", max);
	
	return(0);
}
