#include <stdio.h>

int main (void) {
    int n ;
    scanf ( "%d", &n);
    int R[n];
    
    for ( int i = 0; i < n; i++ ) {
        scanf ( "%d", &R[i]);
    }
    int maxv = -2000000000;
    int minv = R[0];
    
    for ( int i = 1; i < n; i++){
        maxv = maxv < (R[i] - minv) ? R[i] - minv : maxv;
        minv = minv > R[i] ? R[i] : minv;
        
    }
    printf ( "%d\n", maxv);
    return 0;
}
