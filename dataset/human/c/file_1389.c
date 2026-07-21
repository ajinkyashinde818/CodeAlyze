#include<stdio.h>
int main(){
  int n,m,l[200001],o[200001],x,y,i;
  scanf("%d%d",&n,&m);
  for(i=0;i<=n;i++)l[i]=o[i]=0;
  for(i=0;i<m;i++){scanf("%d%d",&x,&y);if(x==1)l[y]=1;if(y==n)o[x]=1;}
  for(i=2;i<n;i++)if(l[i]*o[i]){printf("POSSIBLE");return 0;}
  printf("IMPOSSIBLE");
}
