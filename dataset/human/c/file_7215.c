#include<stdio.h>

int main() {
	int i, j, H, W;

	do {
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0) return 0;

		for (i = 0;i < H;i++) {
			for (j = 0;j < W;j++) {
				if (i % 2 == 1) {
					if (j % 2 == 0) {
						printf(".");
					}
					else {
						printf("#");
					}
				}
				else {
					if (j % 2 == 1) {
						printf(".");
					}
					else {
						printf("#");
					}
				}
			}
			printf("\n");
		}
		printf("\n");
	} while (1);
	return 0;
}
