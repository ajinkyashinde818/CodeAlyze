#include<stdio.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
static inline int IN(void)
{
  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
int main(void)
{
  int cut=0,i=0,N=IN(),K=IN(),A[N]={0},l=1,r=2e9;
  while(i<N){A[i++]=IN();}
  while(l<=r)
  {
    int m=(l+r)/2,temp=0;
    for(i=0;i<N;i++){temp+=(A[i]-1)/m;}
    if(temp<=K){cut=m;r=m-1;}else l=m+1;
  }
  return printf("%d\n",cut),0;
}
