#include <iostream>
#include <numeric>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    int count = 0;
    std::vector<long long> b(n);
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        long long val;
        std::cin >> val;
        b.at(i) = std::abs(val);
        if(val < 0){
            ++count;
        }
    }

    long long ans = std::accumulate(b.begin(), b.end(), 0ll);
    if(0 != count % 2){
        ans -= 2 * *std::min_element(b.begin(), b.end());
    }

    std::cout << ans << std::endl;

    return 0;
}
