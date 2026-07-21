#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i;
    int n;
    scanf("%d", &n);

    int eat_order[n+1];
    eat_order[0] = -1;
    for ( i=1; i<n+1; i++ )
        scanf("%d", &eat_order[i]);

    int ans=0;
    int tmp;
    for ( i=1; i<n+1; i++ ) {
        scanf("%d", &tmp);
        ans += tmp;
    }

    /* if eat No.1 and No.2, then add order_bonus[1] */
    int order_bonus[n];
    for ( i=1; i<n; i++ )
        scanf("%d", &order_bonus[i]);

    for ( i=1; i<n+1; i++ ) {
        if ( eat_order[i] == eat_order[i-1]+1 )
            ans += order_bonus[eat_order[i-1]];
    }
    printf("%d\n", ans);
    return EXIT_SUCCESS;
}
