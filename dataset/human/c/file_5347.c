#include <stdio.h>

int n, m, x, c[13], a[13][13], s, r = -1, l[13];

void d(int i) {
    if (i > n) {
        for (int j = 1; j <= m; j++) if (l[j] < x) return;
        if (r < 0 || s < r) r = s;
        return;
    }
    s += c[i];
    for (int j = 1; j <= m; j++) l[j] += a[i][j];
    d(i + 1);
    s -= c[i];
    for (int j = 1; j <= m; j++) l[j] -= a[i][j];
    d(i + 1);
}

int main() {
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    }
    d(1);
    printf("%d", r);
    return 0;
}
