#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200002
#define LIMIT2 500002
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(i=0;i<n;i++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define zt(a,b) (max((a),(b))-min((a),(b)))
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll nPr(int n,int r){ll i,result=1;rep(i,r){result*=(ll)(n-i);}return result;}
ll nCr(int n,int r){ll i,result=1;if(n<r) return 0;rep(i,min(r,n-r)){result*=(ll)(n-i);result/=(ll)(i+1);}return result;}
#define fact(n) nPr((int)(n),(int)(n))
#define nHr(n,r) nCr((int)((n)+(r)+1),(int)(r))
#define sankaku(x) (((x)*((x)+1))/2)
int dx[8]={1,0,-1,0,1,-1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};
int upint(const void *a, const void *b) { return *(int *)a < *(int *)b ? -1 : *(int *)a > *(int *)b ? 1 : 0; }
int downint(const void *a, const void *b) { return *(int *)a < *(int *)b ? 1 : *(int *)a > *(int *)b ? -1 : 0; }
int upchar(const void* left, const void* right) {return strcmp((char *)left,(char *)right);}
int downchar(const void* left, const void* right) {return strcmp((char *)right,(char *)left);}
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
void initialize(){
    
}
int main(void){
  initialize();
  ll n,m,i,j,k,c,result=0,nw=0;
  int a[LIMIT2]={0};
  char s[LIMIT1];
  int l[LIMIT2]={0},r[LIMIT2]={0};
  int lCount=0,rCount=0;
  
  scanf("%lld %lld %lld",&n,&k,&c);
  scanf("%s",s);
  
  rep(i,n){
    //donyoku mae
    if(nw >= 1){
      nw--;
      continue;
    }else if(s[i]=='x'){
      continue;
    }
    l[lCount]=i+1;
    lCount++;
    nw = c;
  }
  nw = 0;
  for(i=n-1;i>=0;i--){
    //donyoku ketsu
    if(nw >= 1){
      nw--;
      continue;
    }else if(s[i]=='x'){
      continue;
    }
    r[k-1-rCount]=i+1;
    rCount++;
    nw = c;
  }
  rep(i,min(lCount,rCount)){
    //printf("%d %d\n",l[i],r[i]);
    if(l[i]==r[i]) printf("%d\n",l[i]);
  }
  return 0;
}
