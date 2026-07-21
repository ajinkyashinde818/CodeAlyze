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
#define in2(a,b) scanf("%lld %lld",&(a),&(b))
#define in3(a,b,c) scanf("%lld %lld %lld",&(a),&(b),&(c))
#define ind(a) scanf("%lf", &(a))
#define ins(a) scanf("%s", (a))
#define put(a) printf("%lld\n", (a))
#define putd(a) printf("%.15f\n", (a))
//def   puts(a) printf("%s\n", a) 文字はこっち
#define MOD 1000000007
ll powll(ll a,ll b){ll r=1;rep(i,b){r*=a;}return r;}
//your code here!


int main(void){
    char A[55][55], B[55][55];
    ll N, M;
    in2(N,M);
    rep(i,N) ins(A[i]);
    rep(i,M) ins(B[i]);
    ll i,j,issame;
    for(i=0; i<=N-M; i++){
        for(j=0; j<=N-M; j++){//始点を定める
            issame = 1;
            rep(k,M){
                rep(l,M){
                    if(B[k][l]!=A[i+k][j+l]){
                        issame = 0;
                        break;
                    }
                }
            }
            if(issame){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}
