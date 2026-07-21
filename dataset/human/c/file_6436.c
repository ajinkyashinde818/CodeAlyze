#include <stdio.h>

int main(void)
{
	int i,n,s,profit;
	scanf("%d",&n);
	int array[n];

	for (i = 0;i < n;i++)
		scanf("%d",&array[i]);

	s = array[0];
	profit = array[1] - array[0];
	for (i = 1;i < n - 1;i++) {
		if (s > array[i]) {
			s = array[i];
		}
		if (profit < array[i+1] - s) {
			profit = array[i+1] - s;
		}
	}

	printf("%d\n",profit);
	return 0;
	
}
