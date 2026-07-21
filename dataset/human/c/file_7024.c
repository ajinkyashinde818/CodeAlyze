#include <stdio.h>

int main(int argc, const char * argv[])
{
    int h, w, i, j;
    
    scanf("%d", &h);
    scanf("%d", &w);
    
    while (1) {
        for (i = 0; i < h; i++) {
            if (i % 2) {
                for (j = 0; j < w; j++) {
                    if (j % 2) {
                        printf("#");
                    }
                    else
                        printf(".");
                }
            } else {
                for (j = 0; j < w; j++) {
                    if (j % 2) {
                        printf(".");
                    }
                    else
                        printf("#");
                }
            }
            
            printf("\n");
        }
        
        if (h == 0 && w == 0) {
            break;
        }
        
        printf("\n");
        
        scanf("%d", &h);
        scanf("%d", &w);
        
    }
    
    return 0;
}
