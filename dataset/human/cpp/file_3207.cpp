#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    size_t n;
    std::cin >> n;
    
    std::vector<long long> b(n);
    size_t cnt_minus = 0;

    for(auto&& e : b){
        std::cin >> e;
        if(e < 0) cnt_minus++;
    }

    size_t sum = 0;
    size_t min_abs = std::numeric_limits<size_t>::max();
    for(const auto& e : b){
        if(e < 0){
            sum += -e;
        }else{
            sum += e;
        }

        min_abs = std::min<size_t>(min_abs, std::abs(e));
    }

    if(cnt_minus % 2 == 0){
        std::cout << sum << std::endl;
    }else{
        std::cout << sum - (min_abs * 2) << std::endl;
    }

    return 0;
}
