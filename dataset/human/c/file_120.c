#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N, R, G, B;
    int r, g, b;
    int count = 0;
    scanf("%d %d %d %d", &R, &G, &B, &N);
    for(r=0; r<=N/R; r++){
        for(g=0; g<=(N-r*R)/G; g++){
            if( (N-r*R-g*G) % B == 0 ){
                count++;
            }
        }
    }
    printf("%d", count);
}
