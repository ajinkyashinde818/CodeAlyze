#include <stdio.h>
#include <limits.h>

int main(void) {
    int n, min, i, x, diff, max_diff = INT_MIN;

    scanf("%d", &n);
    scanf("%d", &min);
    for (i = 1; i < n; i++) {
        scanf("%d", &x);
        diff = x - min;
        if (max_diff < diff) max_diff = diff;
        if (x < min) min = x;
    }
    printf("%d\n", max_diff);

    return 0;
}
