#include <iostream>

void solve() {
    int n, r;
    std::cin >> n >> r;
    std::cout << r + 100 * (10 - std::min(10, n)) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
