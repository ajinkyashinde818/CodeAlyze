#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
int main(void) {
	int x = 0, i = 0;
	while (true) {
		i++;
		scanf("%d", &x);
		if (x == 0) {
			break;
		}
		printf("Case %d: %d\n", i, x);
	}

	return 0;
}
