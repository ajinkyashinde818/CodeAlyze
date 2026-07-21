#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n, *r, i = 0, min = INT_MAX, result = INT_MIN;
    scanf("%d", &n);
    r = malloc(sizeof(int) * n);
    while (i < n) {
        scanf("%d", &r[i]);
        i++;
    }
    min = r[0];
    for (i = 1; i < n; i++) {
        if (r[i] - min > result) {
            result = r[i] - min;
        }
        if (r[i] < min)
            min = r[i];
    }

    printf("%d\n", result);
}
