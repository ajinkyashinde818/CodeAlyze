#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define rep(i,N) for(int i=0;i<(int)N;i++)
#define SWAP(a,b) (a+=b,b=a-b,a-=b)
static inline void PUT(char c)
{
  static char buf[1<<15],*ptr=buf;
  if(ptr==buf+strlen(buf)||c==0){fwrite(buf,1,ptr-buf,stdout),ptr=buf;}*ptr++=c;
}
static inline int IN(void)
{
  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
static inline void OUT(int a)
{
  if(a<0)PUT('-'),a=-a;
  int d[40],i=0;do{d[i++]=a%10;}while(a/=10);
  while(i--){PUT(d[i]+48);}PUT(' ');
}
int main(void)
{
  int N=IN(),A[N],B[N],j=0,did=-1;
  rep(i,N){A[i]=IN();}rep(i,N){B[i]=IN();}
  rep(i,N)
  {
    if(did!=A[i]){j=0;}
    if(A[i]==B[i])
    {
      while(j<N){if(A[j]!=A[i]&&B[j]!=A[i]){SWAP(B[i],B[j]);break;}j++;}
      if(A[i]==B[i]){return puts("No"),0;}
    }
    did=A[i];
  }
  puts("Yes");rep(i,N){OUT(B[i]);}return puts(""),0;
}
