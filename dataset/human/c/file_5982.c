#include <stdio.h>

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_D

int main(int argc, char **argv) {
    int n, minv, maxp, i, x;
    scanf("%d", &n);
    scanf("%d", &minv);
    maxp = -1000000000;
    for (i = 1; i < n; i++) {
        scanf("%d", &x);
        if (x - minv > maxp)
            maxp = x - minv;
        if (x < minv)
            minv = x;
    }
    printf("%d\n", maxp);
    return 0;
}
