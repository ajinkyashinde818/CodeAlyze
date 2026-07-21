#include <stdio.h>

int book[101];
int sum[101];
int min;
int n;

void rack(int start, int m, int max)
{
	int i;
	int max_next;
//printf("<%d>", max);

	if (min < max){
		return;
	}


	if (start > n){
		if (min > max){
			min = max;
//			printf("<%d>", min);
		}
		return;
	}

	if (m == 1){
		if (start > n){
			return;
		}
		if (max < sum[n] - sum[start - 1]){
			max = sum[n] - sum[start - 1];
		}
		if (min > max){
			min = max;
		}
		return;
	}
	
	for (i = start; i <= n; i++){
		max_next = max;
		if (max_next < sum[i] - sum[start - 1]){
			max_next = sum[i] - sum[start - 1];
		}
		rack(i + 1, m - 1, max_next);
	}
}
		
int main(void)
{
	int m;
	int i, j;
	
	while (1){
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0){
			break;
		}
		
		for (i = 1; i <= n; i++){
			scanf("%d", &book[i]);
		}
		
		sum[0] = 0;
		for (i = 1; i <= n; i++){
			sum[i] = (sum[i - 1] + book[i]);
//printf("(%d=%d+%d)", sum[i], sum[i - 1], book[i]);
		}

		min =  100000000;
		rack(1, m, 0);
		
		printf("%d\n", min);
	}
	return (0);
}
