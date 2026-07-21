#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define chmax(a,b) ((a)=(a)>(b)?(a):(b))
#define chmin(a,b) ((a)=(a)<(b)?(a):(b))
#define abs(p) ((p)>=(0)?(p):(-(p)))
int cmp(const void *a, const void *b);
//your code here!

int main(void){
    ll K, S, ANS=0;
    scanf("%lld %lld", &K, &S);
    rep(x, 0, K+1){
        rep(y, 0, K+1){
            ll z = S -x-y;
            if(z>=0 && z<=K) ANS++;
        }
    }
    printf("%lld\n", ANS);
    return 0;
}

int cmp(const void *a, const void *b){
    ll A=*(ll *)a, B=*(ll *)b;
    if(A==B)return 0;
    else return A>B ? 1:-1;//昇順ソート
}
