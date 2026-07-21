#include <stdio.h>

#define N 200001
#define INF 2000000000

int max(int, int);
int min(int, int);

int main() {
    int i, n, minv, maxv, R[N];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &R[i]);
    }

    minv = R[0];
    maxv = -INF;

    for (i = 1; i < n; i++) {
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    printf("%d\n", maxv);

    return 0;
}


int max(int a, int b) {
    if (b > a) {
        return b;
    }
    return a;
}


int min(int a, int b) {
    if (b > a) {
        return a;
    }
    return b;
}
