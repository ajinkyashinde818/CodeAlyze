#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i;
    int n, k, h;
    int ans=0;
    scanf("%d%d", &n, &k);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &h);
        if ( h >= k )
            ans++;
    }

    printf("%d\n", ans);
    return EXIT_SUCCESS;
}
