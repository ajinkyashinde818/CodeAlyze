#include <stdio.h>

int main(){
    int i, j;
    int h, w;
    
    while(scanf("%d %d", &h, &w), h > 0 && w > 0){
        for(i = 0; i < h; ++i){
            for(j = 0; j < w; ++j){
                putchar((i + j) % 2 == 0 ? '#' : '.');
            }
            
            putchar('\n');
        }
        
        putchar('\n');
    }
    
    return 0;
}
