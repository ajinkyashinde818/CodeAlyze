// AOJ ALDS1_1_D Maximum Profit
// 2018.4.27 bal4u

#include <stdio.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int main()
{
	int n, a, min, ans;

	n = in()-2;
	min = in(), a = in();
	ans = a-min;
	if (a < min) min = a;
	while (n--) {
		a = in();
		if (a < min) min = a;
		else if (a-min > ans) ans = a-min;
	}
	printf("%d\n", ans);
	return 0;
}
