#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>
typedef long long ll;
typedef long double ld;
#define INF (1LL<<60)
#define MOD1 1000000007
/*swap 交換*/
void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a=c;}
/*2つのうち大きい数を返す*/
ll max2(ll a,ll b){return a>=b?a:b;}
/*2つのうち小さい数を返す*/
ll min2(ll a,ll b){return a>=b?b:a;}
/*絶対値*/
ll ABS(ll a){return a>=0?a:(-a);}
typedef struct{
    ll aa;
    ll bb;
}frequent;
// 小大
int compare(const void *a, const void *b){return *(ll *)a - *(ll *)b;}
/*nCk*/
ll nckused[1000][1000];
ll nckreached[1000][1000];
ll comb(ll n,ll k){
    if(n>1000) return (k==0 || k==n)?1:comb(n-1,k-1)+comb(n-1,k);
    if(nckreached[n][k]==1) return nckused[n][k];
    nckreached[n][k] = 1;
    nckused[n][k] = (n==1 || (k==0 || k==n) )?1:comb(n-1,k-1)+comb(n-1,k);
    return (n==1 || (k==0 || k==n) )?1:comb(n-1,k-1)+comb(n-1,k);
}
ll combination(ll n, ll a[n]){
    ll i,r=0;
    for(i=1;i<n;i++){
        if(a[i-1]==a[i]) r++;
    }
    if(r==0) return 6;
    if(r==1) return 3;
    return 1;
    // return comb(n,n-r);
}

int main(void){
    ll k,s,i,j,ans=0,a[3];
    scanf("%lld%lld",&k,&s);
    for(i=k;i>=0;i--){
        a[0]=i;
        // if(s-a[0]>2*k) break;
        for(j=i;j>=0;j--){
            a[1]=j;
            a[2]=s-i-j;
            if(a[2]<0) continue;
            if(a[2]>j) break;
            // printf("%lld %lld %lld\n",a[0],a[1],a[2]);
            ans+=combination(3,a);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
