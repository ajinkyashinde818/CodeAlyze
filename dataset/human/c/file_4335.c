#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIVIDE (1000000007)

int main (void) {
    int n, m, i;
    scanf("%d%d", &n, &m);
    int broken_idx;
    long long step[n+3]; /* init: 0, broken: -1 */
    memset(step, 0, (n+1)*sizeof(long long));
    for ( i=0; i<m; i++ ) {
        scanf("%d", &broken_idx);
        step[broken_idx] = -1;
    }

    step[n+2]=1;
    step[n+1]=0;
    for ( i=n; i>=0; i-- ) {
        if ( step[i] == -1 ) {
            step[i] = 0;
            continue;
        }
        step[i] = (step[i+1]+step[i+2]) % DIVIDE;
    }

    printf("%lld\n", step[0]);
    return EXIT_SUCCESS;
}
