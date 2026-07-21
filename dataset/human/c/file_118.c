#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <limits.h>
#include <math.h>



int main(int argc, char *argv[])
{
    int r, g, b, n;
    int x, y, z;
    long long ans;

    scanf("%d %d %d %d", &r, &g, &b, &n);

    ans = 0;

    for (x = 0; x * r <= n; x++) {
        for (y = 0; x * r + y * g <= n; y++) {
            if ((n - (x * r + y * g)) % b == 0) {
                ans++;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
