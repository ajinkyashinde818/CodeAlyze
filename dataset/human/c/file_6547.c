#include <stdio.h>
/* Maximam Profit */
int main(void)
{
	int n, i, max_dif, min;
	int z[200000];

	scanf("%d", &n); /*整数の個数を入力*/
	for (i=0; i<n; i++){
		scanf("%d", &z[i]); /*整数を入力*/
	}

	min = z[0]; /*最小値の初期設定*/
	max_dif = -1000000000; /*最大値の初期設定*/
	for (i=1; i<n; i++){
		if (z[i] - min > max_dif)
			max_dif = z[i] - min;
		if (z[i] < min)
			min = z[i];
	}
	printf("%d\n", max_dif);

	return 0;
}
