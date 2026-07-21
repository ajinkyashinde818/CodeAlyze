#include <stdio.h>
int main(){
    int R,B,G,N;
    int count = 0;
    int r = 0;
    int g;
    scanf("%d %d %d %d",&R, &B, &G, &N);

    while(r*R <= N){
        g=0;
        while(g*G <= N-r*R){
            if((N - r*R -g*G)%B==0){
                count++;
            }
            g++;
        }
        r++;
    }
    printf("%d\n",count);
    return 0;
}
