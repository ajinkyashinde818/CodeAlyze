#include<stdio.h>
#include<stdlib.h>
#define array(N,t) (t*)calloc(N,sizeof(t))
typedef long long LL;
inline LL IN(void)
{
  LL x=0;short f=0,c=getchar();
  while(c<48||c>57)f^=c==45,c=getchar();
  while(c>47&&c<58)x=x*10+c-48,c=getchar();
  return f?-x:x;
}
signed main(void)
{
  int N=IN(),i,j,p;LL K=IN();
  int *A=array(N,int),*town=array(N,int);
  for(i=0;i<N;i++)A[i]=IN(),town[i]=-1;
  for(i=0,j=0;;i=A[i]-1,j++)if(town[i]<0)town[i]=j;else break;
  for(p=0;K>0;p=A[p]-1,K--)if(i==p){K%=town[i]-j;if(!K)break;}
  free(A),free(town);
  return printf("%d\n",p+1),0;
}
