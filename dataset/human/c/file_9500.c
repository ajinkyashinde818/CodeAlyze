#include <stdio.h>

int main (void)
{
    int n, d, x, i;
    int a;

    scanf("%d", &n);
    scanf("%d %d", &d, &x);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a);
        x += (d - 1) / a + 1;
    }

    printf("%d\n", x);
}
