#include<stdio.h>
int main(){
  int n,m,M=1e9+7,i,a,c[100010],d[100010]={};
  c[0]=c[1]=1;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d",&a);
    d[a]=1;
  }
  for(i=1;i<n;i++)c[i+1]=(c[i]*(1-d[i])+c[i-1]*(1-d[i-1]))%M;
  printf("%d\n",c[n]);
  return 0;
}
