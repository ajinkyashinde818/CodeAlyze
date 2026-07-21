#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<limits>

int main(){
    int N;
    int minus_cnt = 0;
    unsigned long long int res = 0;
    unsigned long long int min = std::numeric_limits<unsigned long long int>::max();
    //std::vector<long long int> A;

    std::cin >> N;
    for(int i=0; i<N; i++){
        long long int _A;
        std::cin >> _A;
        if(_A < 0){
            minus_cnt++;
            res += -_A;
            if(min > -_A) min = -_A;
        }else{
            res += _A;
            if(min > _A) min = _A;
        }
        //A.emplace_back(_A);
    }

    if(minus_cnt%2 == 0){
        std::cout << res << std::endl;
    }else{
        std::cout << res-min*2 << std::endl;
    }

    return 0;
}
