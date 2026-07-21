#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void)
{
    int MOD = 1000000007;

    int n, m;
    scanf("%d %d", &n, &m);
    int a[m+1];
    for (int i=1; i < m+1; i++) scanf("%d", &a[i]);


    long d[n+1];
    int hole = 1;
    for (int i=1; i <= n; i++){
        if (a[hole] == i && hole <= m){
            d[i] = -1;
            hole++;
        }
        else {
            d[i] = 0;
        }
    }

    d[0] = 1;
    if (d[1] == -1) d[1] = 0;
    else d[1] = 1;
    for (int i=2; i <= n; i++){
        if (d[i] == -1){
            d[i] = 0;
        }
        else if(d[i-1] == 0 && d[i-2] == 0){
            d[n] = 0;
            break;
        }
        else{
            d[i] = d[i-1] + d[i-2];
            d[i] %= MOD;
        }
    }

    printf("%ld\n", d[n]);


    return 0;
}
