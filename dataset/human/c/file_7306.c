#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
typedef long long ll;
typedef long double ld;
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define rrep(i,l,r)for(ll i=(l);i>=(r);i--)
#define INF (1LL<<60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 17)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")

void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a=c;}
ll max2(ll a,ll b){return a>=b?a:b;}
ll min2(ll a,ll b){return a>=b?b:a;}
ll min3(ll a, ll b, ll c){return (a<=b && a<=c) ? a : b<=c ? b : c;}
ll max3(ll a, ll b, ll c){return (a>=b && a>=c) ? a : b>=c ? b : c;}
ll minn(ll n, ll a[n]){ll b=INF;rep(i,0,n) b=min2(b,a[i]);return b;}
ll maxn(ll n, ll a[n]){ll b=-INF;rep(i,0,n) b=max2(b,a[i]);return b;}
ll ABS(ll a){return a>=0?a:(-a);}
ll POW(ll a, ll b){ll c=1;rep(i,0,b) c*=a;return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll mod(ll n){return n%=MOD1;}
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

typedef struct{ ll aa , bb;}fr;
int cmp1( const void *p, const void *q ) { return ((fr*)p) ->aa - ((fr*)q)->aa;}

int main(void){
    char s[305][305];
    ll h,w,k;
    scanf("%lld%lld%lld",&h,&w,&k);
    ll num[h][w],st[k][2],p=0;
    rep(i,0,h){
        scanf("%s",s[i]);
    }
    rep(i,0,h){
        rep(j,0,w){
            if(p==k) break;
            if(s[i][j]=='#'){
                st[p][0]=i;
                st[p][1]=j;
                p++;
            }
        }
    }
    p=0;
    ll late=-1;
    rep(i,0,h){
        if(p==k || i!=st[p][0]){
            if(p==0) late=i; 
            else{
                rep(j,0,w){
                    num[i][j]=num[i-1][j];
                }
            }
        }
        if(i==st[p][0]){
            if(p==k-1 || st[p+1][0]!=i){
                rep(j,0,w){
                    num[i][j]=p+1;
                }
                p++;
            }else{
                ll j=0;
                while(j<w){
                    rep(k,j,st[p][1]+1){
                        num[i][k]=p+1;
                    }
                    j=st[p][1]+1;
                    p++;
                    if(st[p][0]!=i) break;
                }
                rep(k,j,w){
                    num[i][k]=p;
                }
            }
        }
    }
    rrep(i,late,0){
        rep(j,0,w){
            num[i][j]=num[i+1][j];
        }
    }
    rep(i,0,h){
        rep(j,0,w) printf("%lld ",num[i][j]);
        PN;
    }
    // printf("\n");
    return 0;
}
