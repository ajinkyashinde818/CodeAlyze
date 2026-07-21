#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::vector<long long> sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] += a[i] + sum[i];
    }

    long long ans = __LONG_LONG_MAX__;
    for (int i = 1; i < n; i++)
    {
        long long x = sum[i];
        long long y = sum[n] - sum[i];
        long long min = std::abs(x - y);
        ans = std::min(ans, min);
    }

    std::cout << ans << "\n";
}
