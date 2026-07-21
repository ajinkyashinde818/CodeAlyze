#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll n;
    std::cin >> n;
    std::vector<ll> sum(n, 0);
    std::cin >> sum[0];
    for(int i = 1; i < n; i++){
        std::cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    ll minVal = 100000000000000000;
    for(int i = 0; i < n - 1; i++){
        ll x = sum[i];
        ll y = sum[n - 1] - sum[i];
        minVal = std::min(minVal, std::abs(x - y));
    }
    std::cout << minVal << std::endl;
    return 0;
}
