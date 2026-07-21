#include <stdio.h>

int main()
{
    int r, g, b, n;
    int tmp, ans=0;
    scanf("%d%d%d%d", &r, &g, &b, &n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            tmp = n - r*i - g*j;
            if(tmp < 0) break;
            if(tmp % b == 0) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
