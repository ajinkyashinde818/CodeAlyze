#include<stdio.h>

int main(void)
{
	int a, b, k, ans[100], i, max, min, o = 1;//oはa、bの公約数の数
	scanf("%d%d%d", &a, &b, &k);
	if (a < b) {
		max = b;
		min = a;
	}
	else {
		max = a;
		min = b;
	}
	for (i = max; i >= 1; --i) {
			if (a % i == 0 && b % i == 0) {
				ans[o] = i;
				++o;
			}
		}
	printf("%d", ans[k]);
	return 0;
}
