#include <stdio.h>

void drawRect(int H, int W) {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			printf("%c", ((x + y)%2 == 0) ? '#' : '.'); 
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	int H = 0, W = 0;
	for (;;) {
		scanf("%d %d", &H, &W);
		if ((H == 0) && (W == 0)) {
			break;
		}
		drawRect(H, W);
	}
	return 0;
}
