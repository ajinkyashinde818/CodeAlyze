#include <stdio.h>
int main(void) {
        long long n, ans = 0, count = 5;
        scanf("%lld", &n);
        if (n % 2 == 1)
                ans = 0;
        else
                while (count <= n) {
                  ans += n/(count*2);
                        count=count*5;
                }
        printf("%lld", ans);
        return 0;
}
