#include <stdio.h>
int main(void)
{
    int R,G,B,N;
    int r,g,b,n=0;
    int x;
    scanf("%d %d %d %d", &R, &G, &B, &N);

        for (r = 0; r <= N; r++) {
            for (g = 0; g <= N; g++) {
                x = N - (R*r + G*g);
                if(N >= R*r + G*g){
                    if(x % B == 0){
                        b = x / B;
                        n = n + 1;
                    }
                }
            }
        }
    printf("%d\n",n);

    return 0;
}
