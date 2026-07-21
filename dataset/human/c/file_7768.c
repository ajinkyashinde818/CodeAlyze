#include <stdio.h>

int main(void)
{

    int n, k[100], p[100], a[100], i;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d %d", &k[i], &p[i]);
        if(k[i] % p[i] == 0)
            a[i] = p[i];
        else
            a[i] = k[i] % p[i];
    }

    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);

    return 0;
}
