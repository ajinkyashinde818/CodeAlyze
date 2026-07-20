/* Example program. */
#include <stdio.h>
void add_one(int *item) {
	++*item;
}
int main(void) {
	int value = 23;
	add_one(&value);
	printf("%d\n", value);
	return 0;
}
