#include<stdio.h>

int main() {
    int n;
    int max = -1000000100, min = 1000000100;
    int i, j;
    int r;

    scanf("%d", &n);
    scanf("%d", &min);
    for(i = 1; i < n; i++) {
        scanf("%d", &r);
        if (max < r - min) max = r - min;
        if (min > r) min = r;
    }

    printf("%d\n", max);
    return 0;
}
