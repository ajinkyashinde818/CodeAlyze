#include<stdio.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
#define rep(i,N) for(int i=0;i<(int)N;i++)
#define swap(a,b) (a+=b,b=a-b,a-=b)
const int MOD=1e9+7;
static inline int IN(void)
{
  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
static inline void Radix32(int *a,const int sz)
{
  int temp[sz];
  rep(j,4)
  {
    int u[256]={},v[256]={};
    rep(i,sz)u[a[i]>>8*j&255]++;
    rep(i,255)u[i+1]+=u[i];
    rep(i,sz){temp[--u[a[sz-1-i]>>8*j&255]]=a[sz-1-i];}j++;
    rep(i,sz)v[temp[i]>>8*j&255]++;
    rep(i,255)v[i+1]+=v[i];
    rep(i,sz)a[--v[temp[sz-1-i]>>8*j&255]]=temp[sz-1-i];
  }
}
int main()
{
  int N=IN(),K=IN(),l,m=0,r,accum=1,sign=1,A[N];long x,y;
  rep(i,N)A[i]=IN(),m+=A[i]<0?1:0;
  Radix32(A,N);
  rep(i,m/2)swap(A[N-m+i],A[N-1-i]);
  rep(i,(N-m)/2)swap(A[i],A[N-m-1-i]);
  rep(i,N/2)swap(A[i],A[N-1-i]);
  if(K&1)accum=A[N-1],sign=(A[N-1]<0?-1:1),N--,K--;
  l=0,r=N-1;
  while(K)
  {
    x=1l*A[l]*A[l+1],y=1l*A[r]*A[r-1];
    if(x*sign>y*sign)x%=MOD,accum=1l*accum*x%MOD,l+=2;
    else y%=MOD,accum=1l*accum*y%MOD,r-=2;
    K-=2;
  }
  return printf("%ld\n",(1l*accum%MOD+MOD)%MOD),0;
}
