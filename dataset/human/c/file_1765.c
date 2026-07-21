#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    int b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int c[n];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &c[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[a[i]];
        if (i > 0 && a[i - 1] + 1 == a[i]) {
            sum += c[a[i - 1]];
        }
    }
    printf("%d\n", sum);
    return 0;
}
