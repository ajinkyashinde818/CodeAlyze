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
ll mod(ll n){n+= n<0?((-n)/MOD1+1)*MOD1:0; return n%=MOD1;}
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

typedef struct{ ll a , b;}fr;
int cmp1( const void *p, const void *q ) { return ((fr*)p) ->a - ((fr*)q)->a;}
int cmp2( const void *p, const void *q ) { return ((fr*)q) ->a - ((fr*)p)->a;}
void strsortup(fr*a,int n){qsort(a,n,sizeof(fr),cmp1);}
void strsortdown(fr*a,int n){qsort(a,n,sizeof(fr),cmp2);}

/*ai<=xとなる最大のi*/
ll lower_bound4(ll n, ll a[n], ll l, ll r, ll x){
    while(r-l>1){
        ll p=(l+r)/2;
        if(a[p]<=x) l=p;
        else r=p;
    }
    return a[r]<=x?r:a[l]<=x?l:-1;
}

/*ai>=xとなる最小のi*/
ll upper_bound(ll n, ll a[n], ll l, ll r, ll x){
    while(r-l>1){
        ll p=(l+r)/2;
        if(a[p]<=x) l=p;
        else r=p;
    }
    return a[l]>=x?l:a[r]>=x?r:-1;
}

int main(void){
    // char ;
    ll a,b,q,ans=0;
    scanf("%lld%lld%lld",&a,&b,&q);
    ll s[a],t[b],x[q];
    rep(i,0,a){
        scanf("%lld",&s[i]);
    }
    rep(i,0,b){
        scanf("%lld",&t[i]);
    }
    rep(i,0,q){
        scanf("%lld",&x[i]);
    }
    rep(i,0,q){
        ll piv1=0,dist=0,piv2=0;
        ans=INF;

        piv1 = lower_bound4(a,s,0,a-1,x[i]);
        if(piv1!=-1){
            dist=0;
            dist+=ABS(s[piv1]-x[i]);

            piv2= lower_bound4(b,t,0,b-1,s[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv1]-t[piv2]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv1]-t[piv2]);
            }

            piv2= upper_bound(b,t,0,b-1,s[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv1]-t[piv2]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv1]-t[piv2]);
            }            
        }

        piv1 = upper_bound(a,s,0,a-1,x[i]);
        if(piv1!=-1){
            dist=0;
            dist+=ABS(s[piv1]-x[i]);

            piv2= lower_bound4(b,t,0,b-1,s[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv1]-t[piv2]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv1]-t[piv2]);
            }

            piv2= upper_bound(b,t,0,b-1,s[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv1]-t[piv2]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv1]-t[piv2]);
            }            
        }

        piv1 = lower_bound4(b,t,0,b-1,x[i]);
        if(piv1!=-1){
            dist=0;
            dist+=ABS(t[piv1]-x[i]);

            piv2= lower_bound4(a,s,0,a-1,t[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv2]-t[piv1]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv2]-t[piv1]);
            }

            piv2= upper_bound(a,s,0,a-1,t[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv2]-t[piv1]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv2]-t[piv1]);
            }            
        }

        piv1 = upper_bound(b,t,0,b-1,x[i]);
        if(piv1!=-1){
            dist=0;
            dist+=ABS(t[piv1]-x[i]);

            piv2= lower_bound4(a,s,0,a-1,t[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv2]-t[piv1]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv2]-t[piv1]);
            }

            piv2= upper_bound(a,s,0,a-1,t[piv1]);
            if(piv2!=-1){
                dist+=ABS(s[piv2]-t[piv1]);
                ans=min2(ans,dist);
                dist-=ABS(s[piv2]-t[piv1]);
            }            
        }

        printf("%lld\n",ans);

    }

    
    // printf("%lld\n",ans);
    return 0;
}
