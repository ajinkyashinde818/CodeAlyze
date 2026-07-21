#include<stdio.h>
//累乗(power)a^n(mod10^9+7)
long long power(long long a,long long n){
  long long count=a,sum=1;
  while(n>0){
    if(n%2==1)
      sum*=count;
    count*=count;
    count%=1000000007;
    sum%=1000000007;
    n/=2;
  }
  return sum;
}

int main(){
  int n,m,x,min=2000000,pattern,i,j,k;
  scanf("%d%d%d",&n,&m,&x);
  pattern=power(2,n);
  int c[n+1],a[n+1][m+1];
  for(i=0;i<n;i++){
    scanf("%d",&c[i]);
    for(j=0;j<m;j++)
      scanf("%d",&a[i][j]);
  }
  for(i=1;i<pattern;i++){
    int b[m+1],sum=0,l=i;
    for(j=0;j<m;j++)
      b[j]=0;
    for(j=0;j<n;j++){
      if(l%2==1){
        for(k=0;k<m;k++)
          b[k]+=a[j][k];
        sum+=c[j];
      }
      l/=2;
    }
    int check=0;
    for(j=0;j<m;j++)
      if(b[j]<x)
        check=1;
    if(check==0 && min>sum)
      min=sum;
  }
  if(min!=2000000)
    printf("%d\n",min);
  else
    printf("-1\n");
  return 0;
}
