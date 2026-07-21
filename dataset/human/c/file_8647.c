#include <stdio.h>
int main() {
	int X, a;
	int b = 0;
	scanf("%d", &X);
	int c[100000];
	for (int i = 0; i<X; i++) {
		scanf("%d", &c[i]);
	}
	for (int j = 0; b<=X; j = a) {
		a = c[j] - 1;
		b++;
		if (a == 1)
		break;
	}
	if (b <=X) {
		printf("%d", b);
	}
	else {
		printf("-1");
	}
	return 0;
}
