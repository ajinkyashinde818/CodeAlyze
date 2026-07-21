#include <stdio.h>

int main()
{
    int r, g, b, n;
    int i, j, cnt;
    scanf("%d",&r);
    scanf("%d",&g);
    scanf("%d",&b);
    scanf("%d",&n);

    cnt = 0;
    for(i=0; i <= n/r; i++)
        for(j=0; j <= (n - i * r) / g; j++)
            if((n - (i * r) - (j * g)) % b == 0)
                cnt++;
    printf("%d\n", cnt);
    return 0;
}
