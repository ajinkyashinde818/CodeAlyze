#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 0;
    scanf("%d\n", &n);
    int min_abs = 1000000001;
    long long int ans = 0;
    int count = 0;
    int buf = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &buf);
        if (buf < 0) count++;
        int ab = abs(buf);
        ans += ab;
        if (ab < min_abs) min_abs = ab;
    }
    if (count%2 == 1) ans -= 2*min_abs;
    printf("%lld\n", ans);
    return 0;
}
