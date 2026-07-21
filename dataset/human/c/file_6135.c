#include <stdio.h>
#define MAX 200000

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a:b

int main(void)
{
    int n, R[MAX], j;
    
    scanf("%d", &n);
    
    for (j = 0; j < n; j++)
    scanf("%d", &R[j]);

    int maxv = -2000000000;
    int minv = R[0];

    for (j = 1; j < n; j++){
    maxv = max(maxv, R[j]-minv);
    minv = min(minv, R[j]);
    }

    printf("%d\n", maxv);

    return 0;
}
