#include<stdio.h>
int f(int a,int b,int n){return b&&(n-a)%b==0?1:0;}  
int i,j,d[5010][5010]={};
int main(){
  int n,m,a[5010],b[5010],M=(1e9)+7;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=0;i<n;i++)scanf("%d",&b[i]);
  d[0][a[0]]=1;
  for(i=a[0]+1;i<m;i++)d[0][i]=(d[0][i-1]+f(a[0],b[0],i))%M;
  for(i=1;i<n;i++){
    d[i][a[i]]=d[i-1][a[i]-1];
    for(j=a[i]+1;j<m;j++)d[i][j]=(d[i][j-1]+d[i-1][j-1]*f(a[i],b[i],j))%M;
  }
  printf("%d\n",d[n-1][m-1]);
  return 0;
}
