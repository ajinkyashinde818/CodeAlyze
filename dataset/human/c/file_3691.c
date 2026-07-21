#include <stdio.h>
typedef long long ll;

ll calc_gcd(ll a, ll b){
    ll  r, tmp;

    //大小入れ替え
    if( a < b ){
        tmp = a;
        a = b;
        b = tmp;
    }

    //ユークリッドの互除法
    r = a % b;
    while( r ){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll calc_lcm(ll a, ll b){
    return (a*b) / calc_gcd(a, b);
}

int main(){
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", calc_lcm(a,b));
    return 0;
}
