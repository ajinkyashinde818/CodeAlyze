#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int a, b;
    scanf("%d%d", &a, &b);

    int large, small;
    if ( a>b ) {
        large = a;
        small = b;
    } else {
        large = b;
        small = a;
    }
    long long ans = large;
    while ( ans%small != 0 )
        ans += large;

    printf("%lld\n", ans);
    return EXIT_SUCCESS;
}
