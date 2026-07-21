#include<stdio.h>
long long n,m,d[100][200010],p=1,i,j;
int main(){
  scanf("%lld %lld",&n,&m);
  for(i=0;i<n;i++)scanf("%lld",&d[0][i+1]);
  for(i=0;i<70;i++){
    for(j=1;j<=n;j++)d[i+1][j]=d[i][d[i][j]];
  }
  for(i=0;i<64;i++){
    if(((1LL<<i)&m))p=d[i][p];//printf("%lld %lld\n",(1LL<<i),p);
  }
  printf("%lld\n",p);
  return 0;
}
