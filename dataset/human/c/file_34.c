//gcc 5.4.0

#include  <stdio.h>

int main(void)
{
    int R, G, B, N;
    int i, j, k;
    int cnt = 0;
    scanf("%d %d %d %d", &R, &G, &B, &N);
    for(i = 0; i <= (int)(N/R); i++){
        for(j = 0; j <= (int)((N-i*R)/G); j++){
            int rest = N - i*R - j*G;
            if(rest % B == 0){
                cnt ++;
            }
        }
    }
    printf("%d", cnt);
}
