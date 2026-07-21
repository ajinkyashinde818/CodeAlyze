#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int r, g, b, n;
    std::cin >> r >> g >> b >> n;
    int ret = 0;
    for (int i = 0; i <= 3000; i++) for (int j = 0; j <= 3000; j++) {
        int m = n - r * i - g * j;
        if (m >= 0 && m % b == 0) ret++;
    }
    std::cout << ret << std::endl;

    return 0;
}
