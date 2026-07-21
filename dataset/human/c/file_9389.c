#include<stdio.h>
int main() {
    int n, d, x, a, i, k;
    scanf("%d%d%d", &n, &d, &x);
    for(i = 1; i <= n; ++i) {
        scanf("%d", &a);
        x += d / a;
        if(d % a != 0) ++x;
    }
    printf("%d\n", x);
    return 0;
}
