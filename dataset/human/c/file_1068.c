#include <stdio.h> 
#include <string.h>
int henkan(char x[]) {
	int z = 1;
	int y = 0;
	int j = 0;
	for (y = 0; y<10; y++) {
		if (x[y] == 'm') {
			j = j + z * 1000;
		}
		if (x[y] == 'c') {
			j = j + z * 100;
		}
		if (x[y] == 'x') {
			j = j + z * 10;
		}
		if (x[y] == 'i') {
			j = j + z * 1;
		}
		if ('2' <= x[y] && x[y] <= '9') {
			z = x[y]-'0';
		}
		else {
			z = 1;
		}

	}
	return j;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int b = 0;
	int c = 0;
	

	for (i = 0; i < n; i++) {
		char a[10] = {};
		char d[10] = {};
		scanf("%s %s", a, d);
		b = henkan(a) + henkan(d);

		if ((b / 1000) > 1) {
			c = b / 1000;
			printf("%d", c);
		}
		if (b / 1000 >= 1) {
			printf("m");
		}
		b %= 1000;

		if ((b / 100) > 1) {
			c = b / 100;
			printf("%d", c);

		}
		if (b / 100 >= 1) {
			printf("c");
		}
		b %= 100;

		if ((b / 10) > 1) {
			c = b / 10;
			printf("%d", c);
		}
		if (b / 10 >= 1) {
			printf("x");
		}
		b %= 10;

		if (b > 1) {
			printf("%d", b);
		}
		if (b >= 1) {
			printf("i");
		}
		printf("\n");
	}

	return 0;
}
