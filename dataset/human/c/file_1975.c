#include<stdio.h>
int main(void) {
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	int ans = 0;

	if (a + b == c) {
		ans = b + c ;
	}
	else if (a + b < c) {
		ans = a+ 1 + b * 2;
	}
	else {
		ans=b + c;
	}
	printf("%d\n", ans);
	return 0;
}
