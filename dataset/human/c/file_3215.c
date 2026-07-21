#include <stdio.h>

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);

    int ai, a, _a, ma=0;

    int i;
    scanf("%d", &ai);
    _a = ai;
    for (i=1; i<n; i++) {
        scanf("%d", &a);
        if (a - _a > ma) {
            ma = a - _a;
        }
        _a = a;
    }

    if (ma < k - (a-ai)) {
        ma = k - (a-ai);
    }

    printf("%d\n", k-ma);

    return 0;
}
