#include<stdio.h>
int main()
{
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    int ans = a + 1;
    if (ans < b + 1)
        ans = b + 1;
    while (k > 0)
    {
        ans--;
        if (a%ans == 0 && b%ans == 0)
            k--;
    }
    printf("%d\n", ans);
    return 0;
}
