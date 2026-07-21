#include <stdio.h>
int main(void) {
    int i, n, k, h;
    int ans=0;

    scanf("%d", &n);
    scanf("%d", &k);
    for (i=0; i<n; i++) {
        scanf("%d", &h);
        if (h >= k) {
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}
