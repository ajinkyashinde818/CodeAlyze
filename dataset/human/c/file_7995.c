#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<tgmath.h>
#include<stdbool.h>
#include<sys/queue.h>
#include<time.h>
#define ll long long
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

const ll mod = 1000000007ll;
ll modpow(ll x, ll y, ll m){
    if(y == 0ll)return 1ll;
    ll res = 1ll, tmp = x;
    while(y){
        if(y&1) res = res * tmp % m;
        tmp = tmp * tmp % m;
        y >>= 1;
    }
    return res;
}
ll pom(ll x, ll y){
    return modpow(x, y, mod);
}
ll COM(ll x, ll y){
    if(x < y) return 0;
    if(x < 0 || y < 0) return 0;
    ll res = 1;
    for(int i=0; i<y; i++){
        res = res * (x-i) % mod * pom(y-i, mod-2) % mod;
    }
    return res;
}

ll x, y;

int main(){
	scanf("%lld%lld", &x, &y);
	if((2*x-y)%3!=0 || (2*y-x)%3!=0){
		puts("0");
		return 0;
	}
	ll i = (2*x-y)/3, j = (2*y-x)/3;
	printf("%lld\n", COM(i+j, i));
	return 0;
}
