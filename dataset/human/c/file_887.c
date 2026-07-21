#include<stdio.h>
int main(){
  long long n,i,j,k,a;
  scanf("%lld",&n);
  for(j=0;n%2==0;j++)n/=2;for(k=1;k*(k+1)/2<=j;k++);a=k-1;
  for(i=3;i*i<n;i+=2){for(j=0;n%i==0;j++)n/=i;for(k=1;k*(k+1)/2<=j;k++);a+=k-1;}
  printf("%lld",a+(n!=1));
}
