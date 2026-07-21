#include <stdio.h>

int main(void) {

	int i = 0, j;
	int data[10000];
	
	while (1) {
		scanf("%d", &data[i]);
		if (data[i] == 0) {
			break;
		}
		else {
			i++;
		}
	}
	
	for (j = 0; j <= i; j++) {
		if (data[j] != 0) {
			printf("Case %d: %d\n", j + 1, data[j]);
		}
	}

	return 0;
}
