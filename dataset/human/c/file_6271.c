#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    //int max;
    int *R;
    int i, j;
    int *max;
    int profit;

    scanf("%d", &n);
    max = malloc(sizeof(int) * n);
    R = malloc(sizeof(int) * n);

#if 0
    0  - 0-4のmax
    1  - 1-4のmax - 0
    2  - 2-4のmax - 1
    3  - 3-4のmax - 2
    4  - 4
#endif

    for(i = 0; i < n; i++) {
        scanf("%d", &R[i]);
        max[i] = R[i];
    }
    for(i = n-2; i >= 0; i--) {
        if(max[i+1] > max[i]) {
            max[i] = max[i+1];
        }
        //printf("[%d]:[%d]\n", i+1, i);
    }


    profit = max[1] - R[0];
    for(i = 0; i < n-1; i++) {
        if(max[i+1]-R[i] > profit) {
            profit = max[i+1]-R[i];
        }
    }
    /*
    max = R[1]-R[0];
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(R[j]-R[i] > max) {
                max = R[j]-R[i];
            }
        }
    }
    */

    printf("%d\n", profit);

    return 0;
}
