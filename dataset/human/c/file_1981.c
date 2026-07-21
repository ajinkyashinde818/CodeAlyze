#include <stdio.h>
#include <stdlib.h>

int main(void){
    long long int a, b, c, ans=0;
    scanf("%lld %lld %lld", &a, &b, &c);
    ans = b;
    if(c-1>(a+b)) ans += (a+b+1);
    else ans += c;
    printf("%lld", ans);
}
