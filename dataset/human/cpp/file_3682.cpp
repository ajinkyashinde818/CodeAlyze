#include <iostream>
#include <cstring>
#include <algorithm>


const int maxn = 1e5 + 5;
long long sq[maxn];
int main(){
    int t;
    std::cin >> t;
    long long ret = 0;
    for(int i =1 ;i <= t ;++ i) std::cin >> sq[i];
    long long mn = sq[1] > 0 ? sq[1]: -sq[1];
    auto min = [](long long x, long long y) -> long long{return x < y ? x :y;};
    auto abs = [](long long x) -> long long {return x > 0 ? x : -x;};
    for(int i = 1 ; i<= t ; ++ i) {
        mn = min(abs(sq[i]),mn);
        ret += abs(sq[i]);
    }
    for(int i = 1; i <= t- 1; ++ i) {
        if (sq[i] < 0) {
            sq[i] = -sq[i];
            sq[i + 1] = -sq[i + 1];
        }
    }
    if(sq[t] < 0) ret = ret - mn - mn;
    return !(std::cout << ret << std::endl);
}
