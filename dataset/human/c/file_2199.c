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
#define INI(n) scanf("%d",&n)
#define INL(n) scanf("%lld",&n)
#define INF 10000000000
#define mod 1000000007
#define X 100000
typedef long long int ll;
ll finv[X];
ll fac[X];
ll inv[X];
ll usort(const void *a, const void *b){return *(ll*)a-*(ll*)b;}
ll dsort(const void *a, const void *b){return *(ll*)b-*(ll*)a;}
ll ssort(const void *a, const void *b){return strcmp((char*)a,(char*)b);}
ll min(ll a,ll b){
  if(a>b)return b;
  return a;
}
ll max(ll a,ll b){
  if(a>b)return a;
  return b;
}
ll z(ll a){return max(a,-a);}
ll gcd(ll a,ll b){if(!b){return a;}else{return gcd(b,a%b);}}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll kt(ll a){
  ll sum=0;
  while(a){
    a/=10;
    sum++;
  }
  return sum;
}
ll ks(ll a){
  ll sum=0;
  while(a){
    sum+=a%10;
    a/=10;
  }
  return sum;
}
void nCrReady(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for (ll i=2;i<X;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
ll nCr(ll n,ll k){return fac[n]*(finv[k]*finv[n-k]%mod)%mod;}

int main(void){
  char s[100001],s1[200001],s2[100001],c[2];
  scanf("%s",s);
  int n,flg=0,cnt1=0,cnt2=0;
  INI(n);
  FOR(n){
    int q;
    INI(q);
    if(q==1){
      flg++;
      flg%=2;
    }else{
      int f;
      INI(f);
      f--;
      scanf("%s",c);
      if(f==flg){
        s1[cnt1++]=c[0];
      }else{
        s2[cnt2++]=c[0];
      }
    }
  }
  char t[2];
  if(flg){
    int l=strlen(s2);
    FOR(l/2){
      t[0]=s2[i];
      s2[i]=s2[l-i-1];
      s2[l-i-1]=t[0];
    }
    l=strlen(s);
    FOR(l/2){
      t[0]=s[i];
      s[i]=s[l-i-1];
      s[l-i-1]=t[0];
    }
    printf("%s%s%s\n",s2,s,s1);
  }else{
    int l=strlen(s1);
    FOR(l/2){
      t[0]=s1[i];
      s1[i]=s1[l-i-1];
      s1[l-i-1]=t[0];
    }
    printf("%s%s%s\n",s1,s,s2);
  }
  return 0;
}
