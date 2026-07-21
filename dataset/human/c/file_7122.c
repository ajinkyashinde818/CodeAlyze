#include <stdio.h>

int main(void)
{
    while (1) {
        int h, w;
        scanf("%d %d", &h, &w);

        if (h == 0 && w == 0) {
            break;
        }

        int row, col;
        for (row = 0; row < h; row++) {
            for (col = 0; col < w; col++) {
                if ((row + col) % 2 == 0) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
