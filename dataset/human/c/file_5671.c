#include<stdio.h>
#include<limits.h>

int main() {
	int max=INT_MIN,min=INT_MAX, temp, n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &temp);
		if (max < temp-min) {
			max = temp-min;
		}
		if(min > temp) {
			min = temp;
		}
	}

	printf("%d\n", max);
}
