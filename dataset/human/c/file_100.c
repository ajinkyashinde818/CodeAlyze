#include<stdio.h>

int main(){
    int R, G, B, N;
    int i,j,k;
    int ans = 0;
    int sum, tmp;

    scanf("%d %d %d %d", &R, &G, &B, &N);

    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            tmp = N-(i*R + j*G);
            if((tmp>=0) && (tmp%B==0)){
                ans +=1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
