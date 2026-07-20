#include <stdio.h>
int main(void) {
	int count = 29;
	printf("%d %c\n", count, 'A' + count % 26);
	return 0;
}
