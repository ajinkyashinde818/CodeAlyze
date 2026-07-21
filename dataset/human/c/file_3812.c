#include <stdio.h>

int main(){
    long long a, b;
    scanf("%lld %lld", &a, &b);
      
    long long x = a*b;
    long long tmp;

    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    long long r = a % b;
    
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    
    printf("%lld", x/b);
    return 0;
}
