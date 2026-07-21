#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

int N;
std::vector<long long int> a;

int main(void){
    std::cin >> N;
    a.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> a[i];
    }

    long long int left  = a[0];
    long long int right = 0;
    for(int i=1; i<N; ++i){
        right += a[i];
    }

    long long int ans = (left < right) ? right-left : left-right;
    for(int i=1; i<N-1; ++i){
        left  += a[i];
        right -= a[i];

        long long int diff = (left<right) ? right - left : left-right;
        ans = (ans > diff) ? diff : ans;
    }

    std::cout << ans << std::endl;
}
