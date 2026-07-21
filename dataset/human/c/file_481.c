#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(){
	int	n;
	long long a[200000] = { 0 };
	long long total = 0;
	long long temp=0,min =LLONG_MAX ;
	long long y;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		total += a[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		temp += a[i];
		y = temp - (total - temp);
		if (y < 0)y = -y;
		if (min > y)
			min = y;
	}
	/*
	if (min > abs(a[n - 1] - (total - a[n - 1])))
		min = abs(a[n - 1] - (total - a[n - 1]));
		*/
	printf("%lld",min);
	return 0;
}
