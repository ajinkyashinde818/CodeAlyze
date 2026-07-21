#include <stdio.h>

int main(){
  int n,i,j,k,m,a[12][12],c[12],x,mm=10000000,d[12],e;
  scanf("%d",&n);
  scanf("%d",&m);
  scanf("%d",&x);
  for(i=0;i<n;i++){
    scanf("%d",&c[i]);
    for(j=0;j<m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(i=1;i<(1<<n);i++){
    e=0;
    for(j=0;j<m;j++){
      d[j]=0;
    }
    for(j=0;j<n;j++){
      if(i&(1<<j)){
        e+=c[j];
        for(k=0;k<m;k++){
          d[k]+=a[j][k];
        }
      }
    }
    for(j=0;j<m;j++){
      if(d[j]<x) break;
    }
    if((j==m)&(e<mm)) mm=e;
  }
  if(mm==10000000) mm=-1;
  printf("%d",mm);
  return(0);
}
