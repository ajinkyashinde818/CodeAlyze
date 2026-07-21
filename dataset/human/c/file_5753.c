#include <stdio.h>

#define MAX(x, y) ((x)>=(y) ? (x):(y))
#define MIN(x, y) ((x)<=(y) ? (x):(y))

int main() {
    int n;
    scanf("%d", &n);
    int minr;
    scanf("%d", &minr);
    int ans = -1 << 30;
    for(int i = 1; i < n; ++i) {
        int r;
        scanf("%d", &r);
        ans = MAX(ans, r - minr);
        minr = MIN(minr, r);
    }
    printf("%d\n", ans);
    return 0;
}
