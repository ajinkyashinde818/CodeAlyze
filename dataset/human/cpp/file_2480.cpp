#include<iostream>
#include<cmath>

long long n,a[100000],minus,min=10000000000,res;

int main(){

    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cin>>a[i];
        if(min>std::abs(a[i]))min=std::abs(a[i]);
        if(a[i]<0)
        minus++;
        res+=abs(a[i]);
    }

    if(minus%2==1)res-=min*2;

    std::cout<<res<<std::endl;

    return 0;

}
