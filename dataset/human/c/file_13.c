#include <stdio.h>

int main() {
    int R, G, B, N, r,g,b;
    while (scanf("%d %d %d %d", &R, &G, &B, &N) != EOF) {
        int cnt = 0;
        int tb = 0, tr=0, tg=0;
        for (r = 0,tr=0; tr <= N; r++, tr += R) {
            for (g= 0,tg=0; tg <= N-tr; g++, tg += G) {
                    if ((N-tg-tr) % B == 0) {
                        cnt++;
                    }

            }
        }
        
        
        printf("%d\n", cnt);
    }
    
    
    return 0;
}
