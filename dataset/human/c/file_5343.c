#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
int solve(int *cost, int **A, int N, int M, int X){
    int ans = 10000000;
    int p = 1;
    for (int i = 0; i < N; i++)  p *= 2; 
    for (int i = 0; i < p; i++) {
        int *exp = (int *)calloc(M , sizeof(int));
        int cst = 0;
        //for (int l = 0; l < M; l++) exp[i] = 0;
        //i(bit)のk番目に立ってたらk番目の本を読む
        for (int k = 0; k < N; k++) {
            if (i & (1 << k)) {
                for (int m = 0; m < M; m++) {
                    exp[m] += A[k][m];
                }
                cst += cost[k];
            }
        }
        for (int m = 0; m < M; m++) {
            if (exp[m] < X)   break; 
            if (m == M - 1) ans = MIN(ans, cst); 
        }
    }
    if (ans == 10000000) ans = -1;
    return ans;
}

int main(void){
    int N,M,X;
    scanf("%d%d%d", &N, &M, &X);
    int *cost = (int *)malloc(N * sizeof(int));
    int **A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(M * sizeof(int *));
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &cost[i]);
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    int ans = solve(cost,A, N, M, X);
    printf("%d\n",ans);
}
