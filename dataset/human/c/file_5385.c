#include<stdio.h>

void main(){
  int n,m,x;
  int c[16];
  int a[16][16];
  scanf("%d %d %d",&n,&m,&x);
  int i,j,k;
  for(i=0;i<n;i++){
    scanf("%d",&c[i]);
    for(j=0;j<m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  
  int limit=1;
  for(i=0;i<n;i++){
    limit*=2;
  }
  int min=-1;
  for(i=1;i<limit;i++){
  	int kingaku=0;
  	int rikaido[16]={0};
  	int tassei=1;
    for(j=0;j<n;j++){
      if((i&(1<<j))!=0){//j番目購入
        kingaku+=c[j];
        for(k=0;k<m;k++){
          rikaido[k]+=a[j][k];
        }
      }
    }
    puts("");
    for(j=0;j<m;j++){
      if(rikaido[j]<x){
        tassei=0;
        break;
      }
    }
    if(tassei){
      if(min==-1){
        min=kingaku;
      }else if(kingaku<min){
        min=kingaku;
      }
    }
  }
  printf("%d\n",min);
}
