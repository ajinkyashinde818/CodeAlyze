#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100
#define rep(i, N) for (i = 0; i < N; i++) //制御変数iを用いてN回転
#define array(N, t) ((t)*)calloc(N, sizeof(t)) //t型N要素の配列を動的確保後0クリア(freeを忘れずに)
#define zero(a); {int iter; rep(iter, sizeof(a)/sizeof((a)[0])) (a)[iter]=0;} //1次元配列aのゼロ初期化?
typedef long long ll;
void printa_int(int *a, int size); //int型の1次元配列aを出力(for debug)

int N, M, X;
int A[12][12];
int C[12];
int Prog[12];

int money(int idx) {
    int i, min = -1, flag = 1;
    rep(i, M) {
        Prog[i] += A[idx][i + 1];
        if (Prog[i] < X) flag = 0;
    }
    if (flag) {
        rep(i, M) {
            Prog[i] -= A[idx][i + 1];
        }
        return A[idx][0];
    }
    for (i = idx + 1; i < N; i++) {
        int temp = money(i);
        if (temp == -1) continue;
        if (min == -1 || min > temp)
            min = temp;
    }
    rep(i, M) {
        Prog[i] -= A[idx][i + 1];
    }
    if (min != -1) min += A[idx][0];
    return min;
}

int main() {
    int i, j, min = -1, pattern;
    scanf("%d %d %d", &N, &M, &X);
    rep(i, N) {
        scanf("%d", C + i);
        rep(j, M) {
            scanf("%d", &A[i][j]);
            A[i][j];
        }
    }
    rep(pattern, 1 << N) {
        int cost = 0, flag = 1;
        zero(Prog);
        rep(i, N) {
            if (pattern >> i & 1) {
                cost += C[i];
                rep(j, M) Prog[j] += A[i][j];
            }
        }
        rep(j, M) {
            if (Prog[j] < X) {
                flag = 0;
                break;
            }
        }
        if (!flag) continue;
        if (min == -1 || min > cost) min = cost;
    }

    printf("%d\n", min);
    return 0;
}

void printa_int(int *a, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d, ", a[i]);
    printf("\n");
}
