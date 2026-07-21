#include <bits/stdc++.h>

const int N = 2e5 + 5;
int a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n; std::cin >> n;
    long long sum0 = 0, sum1 = 0;
    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i]; sum1 += a[i];
    }

    long long ans = 1e16;
    for (int i = 0; i < n - 1; ++ i) {
        sum0 += a[i]; sum1 -= a[i];
        ans = std::min(ans, std::abs(sum0 - sum1));
    }

    std::cout << ans << std::endl;
}
