#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int R[2000000] = {0};
    int Rmin;
    int Vt;
    int ans;

    scanf("%d", &n);
    for ( int i = 0 ; i < n; ++i ) {
        scanf("%d", R + i);
    }

    Rmin = R[0];
    ans = R[1] - R[0];

    for ( int i = 1; i < n; ++i ) {
        if ( Rmin > R[i] ) {
            Rmin = R[i];
        }
        else {
            Vt = R[i] - Rmin;
            if ( Vt > ans ) {
                ans = Vt;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
