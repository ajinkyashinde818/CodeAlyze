#include <stdio.h>

int main(void) {
	
	int a, b, c, d;

	int area1, area2;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);

	area1 = a * b;
	area2 = c * d;

	if (area1 >= area2) {
		printf("%d", area1);
	}
	else {
		printf("%d", area2);
	}


	return 0;
}
