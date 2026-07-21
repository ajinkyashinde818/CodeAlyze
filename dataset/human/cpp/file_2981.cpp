#include <iostream>
#include <vector>

int main(){
    long long n, sum = 0, by = 1, abs_min = 1e9;
    std::cin >> n;
    std::vector<long long> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a.at(i);
        sum += abs(a.at(i));
        abs_min = std::min(abs_min, static_cast<long long>(abs(a.at(i))));
        if(a.at(i) != 0) by *= a.at(i) / abs(a.at(i));
        else by = 0;
    }
    if(by < 0) std::cout << sum - abs_min * 2;
    else std::cout << sum;
}
