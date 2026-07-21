#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i;
    int k, n;

    scanf("%d%d", &k, &n);

    int a[n+1];
    for ( i=0; i<n; i++ )
        scanf("%d", &a[i]);
    a[n] = k + a[0];

    int dist, max_dist = 0;
    for ( i=0; i<n; i++ ) {
        dist = a[i+1] - a[i];
        if ( max_dist < dist )
            max_dist = dist;
    }

    printf("%d\n", k - max_dist);

    return EXIT_SUCCESS;
}
