#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    int n, i;
    int ret;
    int min = 0;
    int max_profit;
    int r;

    ret = scanf("%d\n", &n);
    assert( ret == 1 );
    assert( (2 <= n) && (n <= 200000) );

      /* first value */
    ret = scanf("%d\n", &min);
    assert( ret == 1 );

      /* 2nd value */
    ret = scanf("%d\n", &r);
    assert( ret == 1 );
    max_profit = r - min;

    if ( r < min ) {
        min = r;
    }
    
    for ( i = 2; i < n; i++ ) {
        int p;
        ret = scanf("%d\n", &r);
        assert( ret == 1 );
        assert( (1 <= r) && (r <= 1000000000) );

        p = r - min;
        if ( p > max_profit ) {
            max_profit = p;
        }
        if ( r < min ) {
            min = r;
        }
    }
        
    printf("%d\n", max_profit);

    return 0;
}
