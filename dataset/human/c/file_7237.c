#include <stdio.h>

int main(int argc, const char * argv[])
{

    int H, W;
    int i, j;
    
    while (scanf("%d %d",&H ,&W) != EOF) {
        if (H == 0 && W == 0) break;
        for (i = 0; i < H; i++) {
            if (i % 2 == 0) {
                for (j = 0; j < W; j++) {
                    if (j % 2 == 0) printf("#");
                    else printf(".");
                }
                printf("\n");
            }
            else {
                for (j = 0; j < W; j++) {
                    if (j % 2 == 0) printf(".");
                    else printf("#");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
