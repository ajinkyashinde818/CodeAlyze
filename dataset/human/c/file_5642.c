#include <stdio.h>

int main(void){
    long long x, ans;

    scanf("%lld", &x);
    
    ans = x / 11 * 2;
    x %= 11;

    if(x <= 6 && x > 0){
        printf("%lld", ans + 1);
    }else if(x > 6){
        printf("%lld", ans + 2);
    }else{
        printf("%lld", ans);
    }
    
    return 0;
}
