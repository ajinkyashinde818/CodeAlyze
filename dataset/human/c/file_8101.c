#include<stdio.h>
int main() {
	int a, b, c, d;
	scanf("%d %d %d %d",&a, &b, &c, &d);
	if (a < 1 || a>10 * 10 * 10 * 10) {
		printf("Error");
	}
	if (b < 1 || b>10 * 10 * 10 * 10) {
		printf("Error");
	}
	if (c < 1 || c>10 * 10 * 10 * 10) {
		printf("Error");
	}
	if (d < 1 || d>10 * 10 * 10 * 10) {
		printf("Error");
	}
	int x1;
	int x2;
	x1 = a*b;
	x2 = c*d;
	if (x1 > x2) {
		printf("%d", x1);
	}
	if (x1 < x2) {
		printf("%d", x2);
	}
	if (x1 == x2) {
		printf("%d", x1);
	}



}
