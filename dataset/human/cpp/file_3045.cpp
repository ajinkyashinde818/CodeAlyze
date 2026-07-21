#include <iostream>
#include <algorithm>

int main(){
    int32_t N;
    std::cin >> N;
    constexpr int64_t INF = 1LL<<60;
    int64_t abs_min = INF;
    int64_t abs_sum = 0;
    int32_t num_minus = 0;
    for(int32_t i = 0; i < N; i++){
        int64_t Ai;
        std::cin >> Ai;
        if(Ai < 0) num_minus++;
        abs_min = std::min(abs_min, std::abs(Ai));
        abs_sum += std::abs(Ai);
    }
    if(num_minus % 2 == 1){ 
        abs_sum -= 2 * abs_min;
    }

    std::cout << abs_sum;
    return 0;
}
