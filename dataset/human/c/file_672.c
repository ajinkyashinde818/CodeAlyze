#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
  char a[50][51],b[50][51];
  int n,m,i,j,k,l,o;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)scanf("%s",a[i]);
  for(i=0;i<m;i++)scanf("%s",b[i]);
  for(i=0;i<=n-m;i++)for(j=0;j<=n-m;j++){
    o=1;
    for(k=0;k<m;k++)for(l=0;l<m;l++)if(a[i+k][j+l]!=b[k][l])o=0;
    if(o){printf("Yes");return 0;}
  }
  printf("No");
}
