#include <stdio.h>
int main(){
    int R, G, B, N;
    scanf("%d %d %d %d", &R, &G, &B, &N);
    int cnt = 0;
    int r, g, b;
    r = N/R ;
    g = N/G ;
    b = N/B ;
    for(int i=0;i<r+1;i++){
        for(int j=0;j<g+1;j++){
            if((N-R*i-G*j)%B==0&&(N-R*i-G*j)>-1){
                cnt += 1;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
