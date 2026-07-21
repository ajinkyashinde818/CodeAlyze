#include <stdio.h>
#include <string.h>
#define ll long long
int main(void){
    ll x;
    ll p,q;
    scanf("%lld",&x);
    p=x/11;
    q=x%11;
    if(q==0) printf("%lld\n",p*2);
    else if(q<=6) printf("%lld\n",p*2+1);
    else printf("%lld\n",p*2+2);
    return 0;
}
