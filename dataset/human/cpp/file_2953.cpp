#include <stdio.h>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <typeinfo>
#include <cmath>
#include <numeric>
using namespace std;

int getGCD(int a, int b){
    if(b == 0) return a;
    return getGCD(b, a%b);
}
int main()
{
    int N;
    long long max_sum;
    std::cin >> N;
    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) std::cin >> A[i];
    
    int minus_cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if(A[i] < 0){
            A[i] = -A[i];
            // std::cout << A[i] << "\n";
            minus_cnt = minus_cnt + 1;
            }
    }
    
    if(minus_cnt%2 == 0){
        max_sum = accumulate(A.begin(), A.end(), 0LL);
    }else{
        std::vector<long long>::iterator iter = std::min_element(A.begin(), A.end());
        int index = std::distance(A.begin(), iter);
        A[index] = -A[index];
        max_sum = accumulate(A.begin(), A.end(), 0LL);
    }
    std::cout << max_sum << "\n";
}
