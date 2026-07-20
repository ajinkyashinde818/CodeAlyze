#include <stdio.h>
int main(void) {
	for (int row = 1; row <= 8; ++row) {
		for (int column = 1; column <= row; ++column) {
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}
