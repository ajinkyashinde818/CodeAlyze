#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 60
#define rep(i, N) for (i = 0; i < N; i++) //制御変数iを用いてN回転
#define array(N, t) (t*)calloc(N, sizeof(t)) //t型N要素の1次元配列を動的確保後0クリア(freeを忘れずに)
#define zero(a); {int iter; rep(iter, sizeof(a)/sizeof((a)[0])) (a)[iter]=0;} //1次元配列aのゼロ初期化?
typedef long long ll;
void printa_int(int *a, int size); //int型の1次元配列aを出力(for debug)

int A[SIZE][200002];

int main() {
    int N, i, j;
    ll K;
    scanf("%d %lld", &N, &K);
    rep(i, N) {
        scanf("%d", &A[0][i]);
        A[0][i]--;
    }
    for (i = 1; i < SIZE; i++) {
        rep(j, N)
        A[i][j] = A[i - 1][A[i - 1][j]];
    }
    int pos = 0;
    rep(i, SIZE) {
        if (!K) break;
        if (K & 1) pos = A[i][pos];
        K >>= 1;
    }
    printf("%d\n", pos + 1);

    return 0;
}

void printa_int(int *a, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d, ", a[i]);
    printf("\n");
}
