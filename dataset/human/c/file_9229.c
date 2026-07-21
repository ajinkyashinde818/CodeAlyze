#include <stdio.h>

int main(void)
{
    int n, k;
    scanf("%d", &n);    scanf("%d", &k);
    int a[n];
    int i = 0;
    int c = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= k)
            c++;
    }
    printf("%d", c);
    
    return 0;
}
