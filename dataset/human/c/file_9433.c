#include <stdio.h>

int main()
{
    int n, d, x, a[100], result = 0, i, j;

    scanf("%d%d%d", &n, &d, &x);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        j = 0;
        while (a[i] * j + 1 <= d) {
            result++;
            j++;
        }
    }

    printf("%d\n", result + x);
    return 0;
}
