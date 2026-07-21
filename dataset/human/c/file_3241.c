#include <stdio.h>
#include <string.h>
int main(void)
{
    int i, k, n, a[200000], min;
    scanf("%d %d",&k, &n);
    for (i = 1; i <= n;i++){
        scanf("%d", &a[i]);
    }
    a[0] = a[n] - k;
    min = k;
    for (i = 1; i <= n;i++){
        if(min>k-a[i]+a[i-1]){
            min = k - a[i] + a[i - 1];
        }
    }
    printf("%d", min);

    return 0;
}
