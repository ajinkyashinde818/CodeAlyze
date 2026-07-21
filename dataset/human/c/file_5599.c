#include <stdio.h>
int main(void){
    long long x;
    scanf("%lld",&x);
    long long ans = 0;
    ans += 2 * (x/11);
    x -= 11 * (x/11);
    if(x > 0){
        x -= 6;
        ans += 1;
    }
    if(x > 0){
        x -= 5;
        ans += 1;
    }
    printf("%lld\n",ans);
    return 0;
}
