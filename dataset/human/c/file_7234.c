#include <stdio.h>
int main()
{
    int i, k, h, w;
    
    while(scanf("%d %d", &h, &w), h+w != 0){
        
        for (i = 0; i < h; i++){
            for(k = 0; k < w; k++){
                if(k%2 ==0 && i%2 ==0){
                    printf("#");
                }else if(k%2 ==1 && i%2 == 1){
                    printf("#");
                }else{
                    printf(".");
                }
                
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
