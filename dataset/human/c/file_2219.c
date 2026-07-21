#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long long ll;
typedef long double ld;
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF (1LL<<60)
#define MOD1 1000000007

void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a=c;}/*swap 交換*/
ll max2(ll a,ll b){return a>=b?a:b;}/*2つのうち大きい数を返す*/ 
ll min2(ll a,ll b){return a>=b?b:a;}/*2つのうち小さい数を返す*/ 
ll ABS(ll a){return a>=0?a:(-a);}/*絶対値*/ 
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

typedef struct{
    ll aa;
    ll bb;
}frequent;

int main(void){
    char s[100005],bs[200005],as[200005];
    ll q,front=1,bsmark=0,asmark=0;
    scanf("%s%lld",s,&q);
    ll query[q],n=strlen(s);
    rep(i,0,q){
        scanf("%lld",&query[i]);
        if(query[i]==1){
            front*=-1;
        }else{
            ll a;
            char c[2];
            scanf("%lld%s",&a,c);
            if(a*front==1 || a*front==-2){
                bs[bsmark]=c[0];
                bsmark++;
            }else{
                as[asmark]=c[0];
                asmark++;
            }
        }
    }
    if(front==1){
        rep(i,0,bsmark){
            printf("%c",bs[bsmark-i-1]);
        }
        rep(i,0,n){
            printf("%c",s[i]);
        }
        rep(i,0,asmark){
            printf("%c",as[i]);
        }
    }else{
        rep(i,0,asmark){
            printf("%c",as[asmark-i-1]);
        }
        rep(i,0,n){
            printf("%c",s[n-i-1]);
        }
        rep(i,0,bsmark){
            printf("%c",bs[i]);
        }
    }
    printf("\n");
    return 0;
}
