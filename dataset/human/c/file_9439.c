#include <stdio.h>

int main(void) {
    int n, d, x;
    scanf("%d", &n);
    scanf("%d%d", &d, &x);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= d; j += a[i-1]) {
            x++;
        }
    }
    printf("%d\n", x);
    return 0;
}
