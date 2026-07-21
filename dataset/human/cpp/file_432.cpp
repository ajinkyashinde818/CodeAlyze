#include<iostream>

int r,g,b,n;

long long res;

int main(){

    std::cin>>r>>g>>b>>n;

    for(int i=0;i<=n/r;i++){
        for(int j=0;j<=(n-i*r)/g;j++){
            if((n-i*r-j*g)%b==0)res++;
        }
    }

    std::cout<<res<<std::endl;

    return 0;
}
