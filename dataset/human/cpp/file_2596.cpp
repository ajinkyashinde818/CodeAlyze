#include <bits/stdc++.h>
using i64 = long long;

i64 abs(i64 a) { return a < 0 ? -a : a; }

int main() {
    int n, neg = 0;
    std::cin >> n;
    i64 sum = 0, min = std::numeric_limits<i64>::max();
    for (int i = 0; i < n; i++) {
        i64 in;
        std::cin >> in;
        if (in < 0) neg++;
        sum += abs(in);
        min = std::min(min, abs(in));
    }
    if (neg % 2) sum -= min * 2;
    std::cout << sum << std::endl;

    return 0;
}
