#include <stdio.h>
int main()
{
    int n, res = 0;
    scanf("%d", &n);
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < n; i++)
    {
        res += b[a[i] - 1];
        if (a[i] == a[i+1]-1)
        {
            res += c[a[i]-1];
        }
    }
    printf("%d\n", res);
    return 0;
}
