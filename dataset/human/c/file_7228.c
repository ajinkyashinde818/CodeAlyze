#include <stdio.h>

int main(void)
{
    int i, j, height, width;

    scanf("%d %d", &height, &width);
    while (height || width) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++)
                if ((i + j) % 2 == 0)
                    printf("#");
                else
                    printf(".");
            printf("\n");
        }
        printf("\n");
        scanf("%d %d", &height, &width);
    }

    return 0;
}
