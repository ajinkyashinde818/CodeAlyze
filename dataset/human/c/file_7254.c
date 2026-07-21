#include <stdio.h>

void print_check(int height, int width) {
    int i, j;
    
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            if(i % 2 == 0) {
                if(j % 2 == 0)
                    putchar('#');
                else
                    putchar('.');
            } else {
                if(j % 2 == 0)
                    putchar('.');
                else
                    putchar('#');
            }
        }
         putchar('\n');
    }
}

int main(void) {
    
    int h, w;
        
    while(1) {
        scanf("%d %d", &h, &w);
            
        if(h == 0 && w == 0)
            break;
        
            print_check(h, w);
            putchar('\n');
    
    }
    return(0);
}
