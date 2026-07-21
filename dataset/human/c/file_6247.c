#include <stdio.h>
#include <math.h>

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

typedef long long ll;

#define INF 1145141919
#define size 200000+5

int N;
int arr[size];

int Min(int a, int b) {
    return a > b ? b : a;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

void solver() {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    int ans = arr[1]-arr[0];
    int min = arr[0];
    for (int i = 1; i < N; ++i) {
        ans = Max(ans, arr[i] - min);
        min = Min(min, arr[i]);
    }
    printf("%d\n", ans);
}


int main() {
    solver();
    return 0;
}
