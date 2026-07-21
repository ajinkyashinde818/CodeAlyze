/*
  Contest 067
  C - Splitting Pile
  Rakesh Kumar --> 01/09/2020
 */

#include <bits/stdc++.h>

using ll = long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    ll n = 0;
    std::cin >> n;
    std::vector<ll> v;
    ll total = 0;
    while (n--) {
        ll e = 0;
        std::cin >> e;
        v.emplace_back(e);
        total += e;
    }

    ll min = (1e+16) + 1;
    ll left_sum = v[0];
    for (std::size_t i = 1; i < v.size(); ++i) {
        ll right_sum = total - left_sum;
        min = std::min(min, std::abs(right_sum - left_sum));
        left_sum += v[i];
    }
    std::cout << min << std::endl;

    return 0;
}
