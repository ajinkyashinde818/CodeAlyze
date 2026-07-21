#include <bits/stdc++.h>

using ll = long long;

int n;
std::vector<ll> vec;
std::vector<ll> ans;

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        vec.push_back(a);
    }
    for (int i = 1; i < n; i++) {
        vec[i] += vec[i-1];
    }
    for (int i = 0; i < n-1; i++) {
        ans.push_back(std::abs(vec[i] - (vec[n-1] - vec[i])));
    }
    std::cout << *std::min_element(ans.begin(), ans.end()) << std::endl;
}
