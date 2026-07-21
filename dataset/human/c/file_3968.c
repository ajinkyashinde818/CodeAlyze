#include <stdio.h>

int main (void) {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);

    int min = (a < b)? a : b;
    int ans[min];
    int i, cnt = 0;
    for (i = 1; i <= min; i++) {
        if ( a % i == 0 && b % i == 0 ) {
            ans[cnt] = i;
            cnt++;
        }
    }

    printf("%d\n", ans[cnt - k]);
    return 0;
}
