#include <stdio.h>

int main() {
	int n;
	int a[1000000] = {};
	int min;
	int max = -1000000000;

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	min = a[0];

	for(int j = 1; j < n; j++) {
		if(max < a[j] - min) {
			max = a[j] - min;
		}
		if(min > a[j]) {
			min = a[j];
		}
	}

	printf("%d\n", max);
}
