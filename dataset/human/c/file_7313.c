#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define FOR(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)
#define PRN(n) printf("%d\n",n)
#define PRF(n) printf("%lf\n",n)
#define PRL(n) printf("%lld\n",n)
#define PRS(s) printf("%s\n",s)
#define PRC(c) printf("%c",c)
#define INF 10000000000
#define mod 1000000007
#define X 1000000
typedef long long int ll;
ll finv[X];
ll fac[X];
ll inv[X];
ll u(const void *a, const void *b){return *(ll*)a-*(ll*)b;}
ll d(const void *a, const void *b){return *(ll*)b-*(ll*)a;}
ll z(ll a){
  if(a<0)return -a;
  return a;
}
ll min(ll a,ll b){
  if(a>b)return b;
  return a;
}
ll max(ll a,ll b){
  if(a>b)return a;
  return b;
}
ll gcd(ll a,ll b){
  if(!b)return a;
  return gcd(b,a%b);
}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int kt(ll a){
  int sum=0;
  while(a){
    a/=10;
    sum++;
  }
  return sum;
}
int ks(ll a){
  int sum=0;
  while(a){
    sum+=a%10;
    a/=10;
  }
  return sum;
}
ll nCr(int n,int k){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for (int i=2;i<X;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
  return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
int main(void){
  int h,w,k;
  scanf("%d %d %d",&h,&w,&k);
  int a[h][w];
  int f[h];
  char s[h][w+1];
  FOR(h)scanf("%s",s[i]);
  FOR(h){
    int flg=1;
    int FLG=1;
    FORJ(w){
      if(s[i][j]=='#'){
        FLG=0;
        if(flg){
          for(int t=0;t<j;t++)a[i][t]=k;
          flg--;
        }else{
          k--;
        }
      }
      a[i][j]=k;
    }
    f[i]=FLG;
    if(!f[i])k--;
  }
  int x=-1;
  for(int i=0;f[i];i++)x=i;
  for(int i=x;i>=0;i--){
    f[i]=0;
    FORJ(w)a[i][j]=a[i+1][j];
  }
  FOR(h)if(f[i])FORJ(w)a[i][j]=a[i-1][j];
  FOR(h){
    FORJ(w)printf("%d ",a[i][j]);
    PRS("");
  }
  return 0;
}
