#include <algorithm>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <numeric>

int main() {
    int N;
    std::int64_t a[200000];

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::uint64_t diff = UINT64_MAX;
    std::int64_t x = 0;
    std::int64_t y = std::accumulate(a, a+N, (std::int64_t)0);

    for (int i = 0; i < N-1; i++) {
        x += a[i];
        y -= a[i];
        std::uint64_t d = std::abs(x-y);
        diff = std::min(d, diff);
    }

    std::cout << diff << std::endl;
}
