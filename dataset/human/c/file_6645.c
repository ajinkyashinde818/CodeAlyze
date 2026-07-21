#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

int main(void){
    int *r;
    int n;
    int maxv;
    int minr;
    int j;
    maxv = -1000000000;
    minr = 1000000000;
    scanf("%d", &n);

    r = (int *)malloc(sizeof(int) * n);
    for (j = 0; j < n; j++){
        scanf("%d", &r[j]);
    }

    for (j = 1; j < n; j++){
        minr = min(minr , r[j - 1]);
        maxv = max(maxv, r[j] - minr);
    }

    printf("%d\n", maxv);

    return 0;
}
