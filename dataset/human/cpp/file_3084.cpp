#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    int cnt = 0;
    ll res = 0, min = 1LL << 55;
    for (int i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        if (a < 0) {
            cnt += 1;
            a = -1LL * a;
        }
        res += a;
        min = std::min(min, a);
    }

    if (cnt % 2 == 1) {
        min *= 2LL;
        res -= min;
    }

    std::cout << res << std::endl;
    return 0;
}
