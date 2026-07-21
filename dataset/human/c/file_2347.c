#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define REP(i,l,r) for(ll i=l; i<(ll)(r); i++)
#define max(l,r) ((l)>(r)?l:r)
#define min(l,r) ((l)<(r)?l:r)
#define swap(l,r) {ll tp=l;l=r;r=tp;}
const ll MOD = 1000000007;
int upcmpll(const void *a,const void *b){
    return (*(ll*)a == *(ll*)b?0:(*(ll*)a > *(ll*)b?1:-1));
}
void sort_u(ll *a,int n){qsort(a,n,sizeof(ll),upcmpll);}

int main(){
    int n, k, s; scanf("%d%d%d", &n, &k, &s);
    int a[101010];
    int m = n / k, r = n % k;
    if(k <= n){
        rep(i, n){
            if(i < k) a[i] = s;
            else if(s > 2)a[i] = s/2 + 1;
            else a[i] = 10;
        }
    }

    rep(i, n) printf("%d ", a[i]);
}
