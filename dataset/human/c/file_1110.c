#include <stdio.h>
#include <ctype.h>

int parse(char *a);

int main(void) {
	int i, j, count;
	char numA[9], numB[9], ans[9];

	scanf("%d", &count);
	for (i = 0; i < count; i++) {
		for (j = 0; j<9; j++) {
			numA[j] = 0;
			numB[j] = 0;
			ans[j] = 0;
		}

		scanf("%s %s ", numA, numB);
		output(parse(numA) + parse(numB));
	}
	return 0;
}

int parse(char *a) {
	int ans = 0;
	int i = 1;

	for (; *a; a++) {
		if (isdigit(*a)) {
			i = *a - '0';
			continue;
		}
		switch (*a) {
			case 'm':ans = ans + i * 1000; break;
			case 'c':ans = ans + i * 100; break;
			case 'x':ans = ans + i * 10; break;
			case 'i':ans = ans + i; break;
		}
		i = 1;
	}
	return ans;
}

int output(int ans) {
	int x;

	x = ans / 1000;
	if (x != 0) {
		if (x > 1) {
			printf("%d", x);
		}
		printf("m");
	}

	x = (ans / 100) % 10;
	if (x != 0) {
		if (x > 1) {
			printf("%d", x);
		}
		printf("c");
	}

	x = (ans / 10) % 10;
	if (x != 0) {
		if (x > 1) {
			printf("%d", x);
		}
		printf("x");
	}

	x = ans % 10;
	if (x != 0) {
		if (x > 1) {
			printf("%d", x);
		}
		printf("i");
	}
	printf("\n");
}
