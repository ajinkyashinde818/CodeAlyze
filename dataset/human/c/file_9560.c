#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define chmax(a,b) ((a)=(a)>(b)?(a):(b))
#define chmin(a,b) ((a)=(a)<(b)?(a):(b))
#define abs(p) ((p)>=(0)?(p):(-(p)))
#define swap(a,b) do{ll w=(a);(a)=(b);(b)=w;}while(0)
#define swapd(a,b) do{double w=(a);(a)=(b);(b)=w}while(0)
#define in(a) scanf("%lld", &(a))
#define ind(a) scanf("%lf", &(a))
#define put(a) printf("%lld\n", (a))
#define putd(a) printf("%.15f\n", (a))
//def   puts(a) printf("%s\n", a) 文字はこっち
//your code here!


int main(void){
    ll N, D, X, A[101];
    in(N); in(D); in(X);
    rep(i,N) in(A[i]);
    rep(i,N){
        ll j=0;
        while(1+A[i]*(j++)<=D) X++;
    }
    put(X);
    return 0;
}
