#include <limits.h>
#include <stdio.h>
 
int main(void) {
    int n, R, ans = INT_MIN, tmp;
    scanf("%d%d", &n, &tmp);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &R);
        if (ans < R - tmp) ans = R - tmp;
        if (R < tmp) tmp = R;
    }
    printf("%d\n", ans);
    return 0;
}
