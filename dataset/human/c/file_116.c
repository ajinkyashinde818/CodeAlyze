#include <stdio.h>

int main(void){
    int R, G, B, N;
    int ans = 0;
    scanf("%d%d%d%d", &R, &G, &B, &N);
    int r, g;
    
    for (r = 0;; r++){
        if(r * R > N){
            break;
        }
        for (g = 0;; g++){
            if((r * R + g * G)> N){
                break;
            }
            if((N - R * r - G * g) % B == 0){
                //printf("%d %d %d\n", r, b, g);
                ans += 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0; 
}
