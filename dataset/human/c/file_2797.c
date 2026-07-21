#include <stdio.h>

int main()
{
    int k, s;
    scanf("%d %d", &k, &s);
    int x, y, z, ans;
    ans = 0;
    for (x=0; x<=k; x++)
    {
        for (y=0; y<=k; y++)
        {
            z = s - x - y;
            if (0 <= z && z <=k && x + y + z == s) {
                ans ++;
            }
        }
    }
    printf("%d\n", ans);
}
