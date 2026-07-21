#include <stdio.h>

int main(void)
{
    int H;
    int W;
    scanf("%d" "%d", &H, &W);
    while (H != 0 && W != 0) {             
        for (int j = 0; j < H; ++j) {
            for (int i = 0; i < W; ++i) {
                if (j % 2 == i % 2) {
                    printf("#");
                } else {
                    printf(".");
                }
                }
                printf("\n");
                }
        printf("\n");        
        scanf("%d" "%d", &H, &W);
    }
    return 0;
}
