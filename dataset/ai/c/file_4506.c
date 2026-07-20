#include <stdio.h>
int main(void) {
	int data[] = { 39, 18, 6, 57 };
	int sum = 0;
	for (int index = 0; index < 4; ++index) {
		sum += data[index];
	}
	printf("%d\n", sum);
	return 0;
}
