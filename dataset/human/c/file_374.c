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
int compare(const void *a, const void *b){
    return *(ll *)a>*(ll *)b?1:*(ll *)a<*(ll *)b?-1:0;}

int main(void){
    ll n,r;
    scanf("%lld%lld",&n,&r);
    // ll [n];
    // for(i=0;i<n;i++){
    //     scanf("%lld",&[i]);
    // }
    if(n>=10){
        printf("%lld\n",r);
    }else{
        printf("%lld\n",r+100*(10-n));
    }
    // printf("\n");
    return 0;
}
