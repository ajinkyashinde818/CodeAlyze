#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
#define rep(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
int up(const void *a, const void *b){return *(ll*)a-*(ll*)b;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),up);}

int main(void){
    ll N;
    scanf("%lld",&N);
    ll a[3*N+5];
    rep(i,0,3*N,1){
        scanf("%lld",&a[i]);
    }
    sortup(a,3*N);
    ll sum=0;
    rep(i,N,3*N,2){
        sum+=a[i];
    }
    printf("%lld\n",sum);
    return 0;
}
