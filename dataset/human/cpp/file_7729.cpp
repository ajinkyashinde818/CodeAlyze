#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    int64_t sum[N+1] = {0};
   
    int a;
    for (int i = 0; i < N; ++i) {
        std::cin >> a;
        sum[i+1] = sum[i] + a;
    }

    int64_t min = INT64_MAX;
    for (int i = 1; i < N; ++i) {
        const int64_t x = sum[i];
        const int64_t y = sum[N] - sum[i];
        min = std::min(min, std::abs(x - y));
    }

    std::cout << min << std::endl;

    return 0;
}
