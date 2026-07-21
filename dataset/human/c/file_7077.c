#include <stdio.h>

void draw(int a, int b)
{
	int x, y;
	for (y = 0; y < a; y++) {
		for (x = 0; x < b; x++) {
			if ((x + y) % 2 == 0) {
				printf("#");
			} else {
				printf(".");
			}
		}
		puts("");
	}
	puts("");
}

int main()
{
	int a, b;
	for (;;) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) {
			return 0;
		}
		draw(a, b);
	}
}
