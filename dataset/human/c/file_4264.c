#include<stdio.h>
int main(){
  int n,m,i,j;
  scanf("%d%d",&n,&m);
  int a[m+3];
  long long num[n+3];
  for(i=0;i<m;i++)
    scanf("%d",&a[i]);
  num[0]=1;
  a[m]=n+1;
  j=0;
  for(i=1;i<=n;i++){
    if(a[j]==i){
      num[i]=0;
      j++;
    }
    else if(i==1)
      num[i]=1;
    else{
      num[i]=num[i-1]+num[i-2];
      num[i]%=1000000007;
    }
  }
  printf("%lld\n",num[n]);
  return 0;
}
