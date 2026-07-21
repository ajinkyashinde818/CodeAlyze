#include<stdio.h>

int main(){
    long long int x;
    scanf("%lld",&x);
    
    long long int m=(x-1)/11;
    long long int n=(x+4)/11;
    if(m<n){
        printf("%lld\n",2*n);
    }else{
        printf("%lld\n",2*n+1);
    }
    return 0;
}
