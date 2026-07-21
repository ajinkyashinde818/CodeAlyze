#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int W, H, N;
    int i, px, py, x, y, total, dx, dy, ax, ay;

    scanf("%d%d%d", &W, &H, &N);
    scanf("%d%d", &px, &py);
    for (i = 1, total = 0; i < N; i++) {
        scanf("%d%d", &x, &y);
        dx = x - px;
        dy = y - py;
        ax = abs(dx);
        ay = abs(dy);
        total += ax + ay;
        if (dx * dy > 0) {
            total -= (ax < ay ? ax: ay);
        }
        px = x;
        py = y;
    }
    printf("%d\n", total);
    return 0;
}
