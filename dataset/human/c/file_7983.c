#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long ll;

ll modnum=7+1000000000;

ll modpow(ll a, ll n, ll mod){
    if(n==0) return 1;
    if(n%2==0){
        return modpow(a*a%mod, n/2, mod);
    }else{
        return a*modpow(a, n-1, mod)%mod;
    }
}

int main(void){
    ll X, Y;
    ll a, b;
    ll ans=0;
    ll XpY=1;
    ll Xa=1;
    ll Ya=1;
    ll Xinv;
    ll Yinv;
    

    scanf("%lld %lld", &X, &Y);

    if((2*X-Y)%3!=0 || (2*Y-X)%3!=0 || (2*X-Y)<0 || (2*Y-X)<0){
        printf("0");
        return 0;
    }
    a=(2*X-Y)/3;
    b=(2*Y-X)/3;


    ll i;
    for(i=1; i <= a; i++){
        Xa=(Xa*i)%modnum;
    }
    for(i=1; i <= b; i++){
        Ya=(Ya*i)%modnum;
    }
    for(i=1; i <= a+b; i++){
        XpY=(XpY*i)%modnum;
    }
    
    Xinv=modpow(Xa, modnum-2, modnum);
    Yinv=modpow(Ya, modnum-2, modnum);

    ans = (XpY*Xinv)%modnum;
    ans = (ans*Yinv)%modnum;

    printf("%lld", ans%modnum);
    return 0;
}
