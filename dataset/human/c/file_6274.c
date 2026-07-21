#include<stdio.h>
#include<limits.h>

int main() {
	int n,i,t;
	int min, sa = INT_MIN;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		if (i == 0) min = t;
		else {
			if (sa < (t - min)) sa = (t - min);
			if (t < min) min = t;
		}
}
	printf("%d\n", sa);
	return 0;
}
