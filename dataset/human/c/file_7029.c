#include <stdio.h>

int main(void) {
    int H, W, i, j;
    char c[] = {'#', '.'};
    while (scanf("%d", &H), scanf("%d", &W), H != 0) {
	for (i = 0; i < H; i++) {
	    for (j = 0; j < W; j++) {
		printf("%c", c[(i + j) % 2]);
	    }
	    printf("\n");
	}
	printf("\n");
    }
    return 0;
}
