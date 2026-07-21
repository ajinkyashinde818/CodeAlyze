#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int N, M;

    scanf("%d%d", &N, &M);

    int g[N+1];
    int f[N+1];

    for(int i = 2; i <= N-1; i++){
        g[i] = 0;
        f[i] = 0;
    }

    int a[M], b[M];

    for(int i = 0; i < M; i++){
        scanf("%d%d", &a[i], &b[i]);
        if(a[i] == 1){
            g[b[i]] = 1;
        }
        if(b[i] == N){
            f[a[i]] = 1;
        }
    }

    int t = 0;

    for(int i = 2; i <= N-1; i++){
        if(g[i] == 1 && f[i] == 1){
            t = 1;
            break;
        }
    }

    if(t == 1){
        printf("POSSIBLE\n");
    }else{
        printf("IMPOSSIBLE\n");
    }

    return 0;
}
