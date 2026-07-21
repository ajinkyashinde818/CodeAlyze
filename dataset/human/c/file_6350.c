#include <stdio.h>
#define N 200000

int main(void) {
    int i,n,minv,maxv;
    int r[N];

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &r[i]);
    }

    minv = r[0];
    maxv = r[1]-r[0];

    for(i=1; i<n; i++) {
        if(maxv < r[i]-minv)
            maxv = r[i]-minv;
        else if(minv > r[i])
            minv = r[i];
    }

    printf("%d\n", maxv);

    return 0;


}
