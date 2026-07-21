#include<stdio.h>

typedef long long ll;

int GCD(ll a, ll b){
    ll r;
    while( (r=a%b)!=0 ){      /*ユークリッドの互除法*/
        a=b;
        b=r;    
    }
    return b;
}

ll LCM(ll a, ll b){
    return (a*b) / GCD(a,b);
}

int main(void)
{
    ll a, b;

    scanf("%lld %lld", &a, &b);


    printf("%lld", LCM(a, b));
 
    return 0;
}
