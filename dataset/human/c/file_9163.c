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
typedef long long int ll;
ll u(const void *a, const void *b){
    return *(ll*)a-*(ll*)b;
}
ll d(const void *a, const void *b){
    return *(ll*)b-*(ll*)a;
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
int main(void){
  int n,k;
  scanf("%d %d",&n,&k);
  int a[n];
  FOR(n)scanf("%d",&a[i]);
  qsort(a,n,sizeof(int),d);
  FOR(n){
    if(a[i]<k){
      PRN(i);
      return 0;
    }
  }
  PRN(n);
  return 0;
}
