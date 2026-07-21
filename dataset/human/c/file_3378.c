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
#define mod 1000000007
typedef long long int ll;
int u(const void *a, const void *b){
    return *(ll*)a-*(ll*)b;
}
int d(const void *a, const void *b){
    return *(ll*)b-*(ll*)a;
}
int min(int a,int b){
  if(a>b)return b;
  return a;
}
int max(int a,int b){
  if(a>b)return a;
  return b;
}
int gcd(int a,int b){
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
char s[100001];
int main(void){
  char c[4][8]={"maerd","remaerd","esare","resare"};
  int l[4]={5,7,5,6};
  scanf("%s",s);
  int n=strlen(s);
  FOR(n/2){
    int t=s[i];
    s[i]=s[n-i-1];
    s[n-i-1]=t;
  }
  int x=0;
  while(x<n){
    int y=x;
    FOR(4){
      int f=1;
      FORJ(l[i])if(s[x+j]!=c[i][j])f=0;
      if(f)x+=l[i];
    }
    if(x==y){
      PRS("NO");
      return 0;
    }
  }
  PRS("YES");
  return 0;
}
