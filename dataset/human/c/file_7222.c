#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int c;
	int d;
	while (1) {
		scanf("%d %d", &a, &b);
		if ((a == 0) && (b == 0)) {
			break;
		}
		else {
			for (c = 1; c <= a; c++) {
				for (d = 1; d <= b; d++) {
					if (c % 2 == 1) {
						if (d % 2 == 1) {
							printf("#");
						}
						else if (d % 2 == 0) {
							printf(".");
						}
					}
					else if (c % 2 == 0) {
						if (d % 2 == 1) {
							printf(".");
						}
						else if (d % 2 == 0) {
							printf("#");
						}
					}
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	
	return (0);
}
