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
    ll N, A[21], B[21], C[21], ans=0;
    scanf("%lld", &N);
    rep(i, 1, N+1) scanf("%lld", A+i);
    rep(i, 1, N+1) scanf("%lld", B+i);
    rep(i, 1, N) scanf("%lld", C+i);
    rep(i, 1, N+1){
        ans += B[A[i]];
        if(i>1){
            if(A[i]-A[i-1]==1) ans += C[A[i-1]];
        }
    }
    printf("%lld\n", ans);
    return 0;
}

int cmp(const void *a, const void *b){
    ll A=*(ll *)a, B=*(ll *)b;
    if(A==B)return 0;
    else return A>B ? 1:-1;//昇順ソート
}
