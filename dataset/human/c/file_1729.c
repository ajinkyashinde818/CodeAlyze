#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, sum = 0;

    scanf("%d", &n);

    int a[20], c[20], b;

    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &b);
        sum += b;
    }
    for(int i = 0; i < n - 1; ++i)
        scanf("%d", &c[i]);

    for(int i = 1; i < n; ++i)
        if(a[i] - 1 == a[i - 1])
            sum += c[a[i - 1] - 1];

    printf("%d", sum);

    return 0;
}
