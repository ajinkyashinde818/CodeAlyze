#include<bits/stdc++.h>

int main()
{
    int n;
    long long sum = 0;
    std::vector<int> v;
    std::cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        std::cin>>v[i];
        sum += v[i];
    }
    long long min_abs = 10000000000000000;
    long long cur = v[0];
    for(int i=1;i<n;i++){
        min_abs = std::min(std::abs(sum - cur*2),min_abs);
        cur += v[i];
    }
    std::cout<<min_abs<<std::endl;
}
