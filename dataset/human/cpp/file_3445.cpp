#include <algorithm>
#include <iostream>
#include <cstdio>

int n, cntMinus;
int a[1000010];
long long ans;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], cntMinus += a[i] <= 0;
    if (cntMinus % 2)
    {
        int _min = 0x7f7f7f7f;
        for (int i = 1; i <= n; ++i)
            ans += a[i] > 0 ? a[i] : -a[i], _min = std::min(_min, a[i] > 0 ? a[i] : -a[i]);
        ans -= 2 * 1ll * _min;
    }
    else
        for (int i = 1; i <= n; ++i)
            ans += a[i] > 0 ? a[i] : -a[i];
    std::cout << ans << std::endl;
    return 0;
}
