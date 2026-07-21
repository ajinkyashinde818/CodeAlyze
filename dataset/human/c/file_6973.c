#include <stdio.h>

int main(int argc, const char * argv []){
    int h[300], w[300]; //???????¨?
    int num=0;
    
    while (1) {
        scanf("%d %d", &h[num], &w[num]);
        if (h[num]==0 && w[num]==0) {
            break;
        }
        num++;
    }
    
    for (int k=0; k<num; k++) {
        
        for (int i=0; i<h[k]; i++) {
            for (int j=0; j<w[k]; j++) {
                if (j % 2 == 0 && i % 2 ==0) {
                    printf("#");
                }else if (j % 2 == 1 && i % 2 ==0) {
                    printf(".");
                }else if (j % 2 == 0 && i % 2 ==1) {
                    printf(".");
                }else if (j % 2 == 1 && i % 2 ==1) {
                    printf("#");
                }
            }
            printf("\n");
        }
        printf("\n");
        
    }
    
    
    return 0;
}
