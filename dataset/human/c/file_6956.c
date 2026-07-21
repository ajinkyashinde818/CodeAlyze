#include <stdio.h>

int main(void)
{
    int h, w;
    int i, j;
    while (1) {
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0) {
            break;
        } else {
            for (i = 0; i < h; ++i) {
                if (i % 2 == 0) {   //偶数行目
                    for (j = 0; j < w; ++j) {
                        if (j % 2 == 0) {
                            printf("#");
                        } else {
                            printf(".");
                        }
                    }
                    printf("\n");
                } else {    //奇数行目
                    for (j = 0; j < w; ++j) {
                        if (j % 2 == 0) {
                            printf(".");
                        } else {
                            printf("#");
                        }
                    }
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
