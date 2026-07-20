#include <stdio.h>
int main(void) {
	int data[] = { 65, 6, 9 };
	for (int pass = 0; pass < 2; ++pass) {
		for (int index = 0; index < 2 - pass; ++index) {
			if (data[index] > data[index + 1]) { int temp = data[index]; data[index] = data[index + 1]; data[index + 1] = temp; }
		}
	}
	printf("%d\n", data[0]);
	return 0;
}
