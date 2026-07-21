#include <stdio.h>

int main(void)
{
    int n;
    static long r[200000];
    long maxv;
    long minv;
    
    scanf("%d", &n);
    
    for ( int i = 0; i < n; i++ ) {
        scanf("%ld", &r[i]);
    }
    
    maxv = r[1] - r[0];
    minv = r[0];
    
    for ( int j = 1; j < n; j++ ) {
        if ( r[j] - minv > maxv ) {
            maxv = r[j] - minv;
        }
        if ( r[j] < minv ) {
            minv = r[j];
        }
    }
    
    printf("%ld\n", maxv);
    
    return 0;
}
