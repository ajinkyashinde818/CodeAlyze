#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define rep(i, n) for (i = 0; i < n; i++)
#define rrep(i, n) for (i = n; i >= 0; i--)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int eq(char a[50][50], int x, int y, char b[50][50], int s) {
    int i, j;
    rep(i, s) rep(j, s) {
        if (a[x + i][y + j] != b[i][j]) return 0;
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    char a[50][50], b[50][50];
    int i, j;
    rep(i, n) {
        rep(j, n) a[i][j] = getchar();
        getchar();
    }
    rep(i, m) {
        rep(j, m) b[i][j] = getchar();
        getchar();
    }

    rep(i, n - m + 1) rep(j, n - m + 1) {
        if (eq(a, i, j, b, m)) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
