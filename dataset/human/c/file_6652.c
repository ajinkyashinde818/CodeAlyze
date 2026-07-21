#include <stdio.h>
#include <math.h>

#define RMAX pow(10, 9)
#define RMIN 1

int main (void) {
    int n, r, rmin=2*RMAX;
    int res = RMIN-RMAX-1;

    scanf ("%d", &n);

    for (int i=0; i<n; i++) {
        scanf ("%d", &r);
        if (res < r-rmin) res = r-rmin;
        if (r < rmin) rmin = r;
    }

    printf ("%d\n", res);
    
    return 0;
}
