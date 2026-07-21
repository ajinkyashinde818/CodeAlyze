#include <bits/stdc++.h>
using longlong=long long;

int main(){
    std::cin.tie(nullptr);std::cin.sync_with_stdio(false);
    int n,r;std::cin>>n>>r;
    if(n<=10)r+=100*(10-n);
    std::cout<<r<<std::endl;
}
