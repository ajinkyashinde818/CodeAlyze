#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i + 1];
        a[i + 1] += a[i];
    }

    i64 ret = std::numeric_limits<i64>::max();
    for (int i = 1; i < n; i++) {
        i64 x = a[i], y = a[n] - x;
        if (x < y) std::swap(x, y);
        ret = std::min(ret, x - y);
    }

    std::cout << ret << std::endl;

    return 0;
}
