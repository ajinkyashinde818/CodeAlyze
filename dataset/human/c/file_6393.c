#include <limits.h>
#include <stdio.h>

static const int MAX_NUM_INPUT = 200000;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int n, i;
    int R[MAX_NUM_INPUT];
    int maxv = INT_MIN;
    int minv;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &R[i]);
    }
    
    minv = R[0];
    
    for (i = 1; i < n; i++) {
        maxv = MAX(maxv, R[i] - minv);
        minv = MIN(minv, R[i]);
    }
    
    printf("%d\n", maxv);
    
    return 0;
}
