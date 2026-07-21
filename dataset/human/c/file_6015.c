/*
 *
 * maximum profit
 *
 */

#include <stdio.h>

#define MAX_N 200000
#define MIN -1000000000

int main(void) {
    int n, R[MAX_N+1], maxv, minv;
    
    scanf("%d", &n);

    int i;
    for(i=0;i<n;i++){
        scanf("%d", &R[i]);
    }

    minv = R[0];
    maxv = MIN;
    for(i=1;i<n;i++){
        if(maxv < (R[i]-minv)){
            maxv = R[i]-minv;
        }

        if(minv > R[i]){
            minv = R[i];
        }
    }

    printf("%d\n", maxv);

    return 0;
}
