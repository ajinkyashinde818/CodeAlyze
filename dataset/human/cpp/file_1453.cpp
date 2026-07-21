#include <bits/stdc++.h>

int main() {
    long long n;
    std::cin >> n;
    for (auto i = 2ll; ; i++) {
        auto t = i * (i - 1) / 2;
        if (t > n) {
            std::cout << "No" << std::endl;
            return 0;
        } else if (t == n) {
            std::cout << "Yes" << std::endl;
            std::cout << i << std::endl;
            int c = 2 * n / i;
            std::vector<std::deque<std::pair<int, int>>> g(i);
            int cnt = 1;
            for (int j = 0; j < i; j++) {
                for (int k = j + 1; k < i; k++) {
                    g[j].push_back(std::make_pair(k, cnt));
                    g[k].push_back(std::make_pair(j, cnt));
                    cnt++;
                }
            }
            for (auto& el : g) {
                std::cout << c << " ";
                for (auto e : el) std::cout << e.second << " ";
                std::cout << std::endl;
            }
            return 0;
        }
    }

    return 0;
}
