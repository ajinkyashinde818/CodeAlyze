#include <stdio.h>

int main()
{
	/* 目的 : 入力の最小公倍数を求める */
	
	int a;		/* ユーザー入力A */
	int b;		/* ユーザー入力B */
	scanf("%d %d", &a, &b);

	int mul_a;			/* aにかける数 multiplier_a */
	int mul_b;			/* bにかける数 multiplier_b */
	long long int result_a;		/* aの計算結果 */
	long long int result_b;		/* bの計算結果 */
	
	mul_a = 1;
	mul_b = 1;
	result_a = a;
	result_b = b;

	while(1){
		while(result_a > result_b){
			result_b = (long long int)b * mul_b;
			++mul_b;
		}
		while(result_a < result_b){
			result_a = (long long int)a * mul_a;
			++mul_a;
		}
		if(result_a == result_b)
			break;
	}
	printf("%lld\n", result_a);
	return 0;
}
