#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y)(x>y?x:y)
#define min(x,y)(x>y?y:x)
#define MOD (int)1e9+7
int dx4[]={1,0,-1,0};
int dy4[]={0,-1,0,1};
typedef long long int ll;
typedef unsigned long long int ull;
ll gcd(ll x,ll y){if(!y)return x;return gcd(y,x%y);}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
void swap(ll *x,ll *y){ll tmp=*x;*x=*y;*y=tmp;}
int asc_cmp(const void* X,const void* Y){ll x=*(int*)X,y=*(int*)Y;if(x<y)return -1;else if(x==y)return 0;else return 1;}
int desc_cmp(const void* X,const void* Y){ll x=*(int*)X,y=*(int*)Y;if(x<y)return 1;else if(x==y)return 0;else return -1;}
typedef struct pair_{
    int x;
    int y;
}pair_t;

int main(){
    int k,n;scanf("%d %d",&k,&n);
    int a[200000];for(int i=0;i<n;i++)scanf("%d",&a[i]);
    ll dist[200001];
    int max=-1;
    int x,y;
    for(int i=1;i<n;i++){
        dist[i]=a[i]-a[i-1];
        if(dist[i]>max){
            x=i;y=i-1;
            max=dist[i];
        }
    }

    ll sum1,sum2;
    sum1=sum2=0;
    for(int i=1;i<n;i++){
        sum1+=dist[i];
    }

    for(int i=x+1;i<n;i++){
        sum2+=a[i]-a[i-1];
    }
    sum2+=k-a[n-1]+a[0];
    for(int i=1;i<=y;i++){
        sum2+=a[i]-a[i-1];
    }
    printf("%lld\n",sum1<sum2?sum1:sum2);
    
}
