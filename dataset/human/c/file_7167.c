#include <stdio.h>

int main(int argc, const char * argv[])
{

    int w, h, x, y;
    
    while(1) {
        scanf("%d %d", &h, &w) ;
        if (h == 0 && w == 0) {
            break;
        } else {
            for(x = 0; x < h; x++) {
                for(y = 0; y < w; y++) {
                    if ((x + y) % 2 == 0) {
                        printf("#");
                    } else {
                        printf(".");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    
    return 0;
}
