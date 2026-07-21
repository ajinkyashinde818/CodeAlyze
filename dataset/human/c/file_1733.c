#include "stdio.h"



int main(void) {

	int number;
	int array[20], barray[20], carray[19];
	int sum = 0;
	scanf("%d", &number);

	for (int i = 1; i<=number; i++) {
		scanf("%d", &array[i]);
	}
	for (int i = 1; i<=number; i++) {
		scanf("%d", &barray[i]);
	}
	for (int i = 1; i<=number - 1; i++) {
		scanf("%d", &carray[i]);
	}

	for (int i = 1; i<=number; i++) {
		sum += barray[array[i]];
			if ((array[i] == array[i-1] + 1) && (i != 1)) {
				sum += carray[array[i-1]];
			}
	}
	printf("%d\n", sum);

	return 0;
}
