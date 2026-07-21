#include<stdio.h>
#define mod 1000000007
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  int i,a[n+1],k;
  for(i=0;i<=n;i++)a[i]=1;
  for(i=0;i<m;i++){
    scanf("%d",&k);
    a[k]=0;
  }
  int s[n+1];
  s[0]=1;s[1]=a[1];
  for(i=2;i<=n;i++){
    s[i]=(s[i-1]+s[i-2])*a[i]%mod;
  }
  printf("%d",s[n]);
}
