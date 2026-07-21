#include<stdio.h>
int main(){
  int n,m,a,x[100010],y[100010],i;
  const int mod=1000000007;
  scanf("%d %d\n",&n,&m);
  for(i=0;i<=n;i++){
    x[i]=0;
    y[i]=0;
  }
  for(i=0;i<m;i++){
    scanf("%d",&a);
    x[a]=1;
  }
  y[0]=1;
  for(i=1;i<=n;i++){
    if(x[i]==1){
      continue;
    }
    if(i-2>=0 && x[i-2]==0){
      y[i]=(y[i]+y[i-2])%mod;
    }
    if(x[i-1]==0){
      y[i]=(y[i]+y[i-1])%mod;
    }
  }
  printf("%d\n",y[n]);
  return 0;
}
