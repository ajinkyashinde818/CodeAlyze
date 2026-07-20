#include <stdio.h>
int main(void) {
	int value = 16;
	printf("%d %c\n", value, 'A' + value % 26);
	return 0;
}
