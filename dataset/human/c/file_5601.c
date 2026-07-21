#include <stdio.h>
int main(void){
    // Your code here!
    long long x;
    long long cnt;
    int rem;
    
    scanf("%lld",&x);
    
    rem = x % 11;
    cnt = (x / 11)*2;
    
    if(rem == 0);
    else if(rem <= 6){
        cnt += 1;
    }
    else if(rem <= 10){
        cnt += 2;
    }
    
    printf("%lld\n",cnt);
}
