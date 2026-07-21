//
// !!!WARNING!!!
// AUTO SUBMITTION TEST ALERT
// !!!WARNING!!!
//

#include <stdio.h>

#define MAX(x, y) ((x)>=(y) ? (x):(y))
#define MIN(x, y) ((x)<=(y) ? (x):(y))

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    // init sufficiently small value
    int ans = -1 << 30;
    // minr: minimum rate
    int minr;
    scanf("%d", &minr);
    for(int i = 1; i < n; ++i) {
        int r;
        scanf("%d", &r);
        ans = MAX(ans, r - minr);
        minr = MIN(minr, r);
    }
    printf("%d\n", ans);
    return 0;
}
