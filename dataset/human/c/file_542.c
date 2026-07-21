#include<stdio.h>
long int lbs(long int a){return a>0?a:-a;}
int main(){
  long int n,a[200000],k=0,s=0,i,m=1L<<60L;
  scanf("%ld",&n);
  for(i=0;i<n;i++){scanf("%ld",&a[i]);s+=a[i];}
  for(i=0;i<n;i++){k+=a[i];if(i+1<n)m=lbs(s-k*2L)<m?lbs(s-k*2L):m;}
  printf("%ld",m);
}
