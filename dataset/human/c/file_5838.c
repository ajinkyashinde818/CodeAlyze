#include <stdio.h>

int main(void) {
	int n, i, num, min = 0, profit;

	scanf("%d", &n);
	for(i = 0; i < 2; i++) {
		scanf("%d", &num);	
		if(min == 0) {
			min = num;	
			continue;
		}
		profit = num - min;
		if(num < min)
			min = num;
	}
	for(; i < n; i++) {
		scanf("%d", &num);	
		if(profit < num - min)
			profit = num - min;
		if(num < min)
			min = num;
	}
	printf("%d\n", profit);
	return 0;
}
