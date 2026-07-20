/* Example program. */
#include <stdio.h>
int main(void) {
	int data[] = { 69, 19, 8, 88 };
	int sum = 0;
	for (int index = 0; index < 4; ++index) {
		sum += data[index];
	}
	printf("%d\n", sum);
	return 0;
}
