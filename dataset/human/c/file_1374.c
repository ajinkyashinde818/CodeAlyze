#include <stdio.h>

int main(){

  int N,M,i,j,a[200000],b[200000],c[200000],x=1,y=0,z=0,max;
  scanf("%d %d",&N,&M);
  for(i=0;i<M;i++){
    scanf("%d %d",&a[i],&b[i]);
  }
      z=N/2;
  for(i=0;i<M;i++){
    if(a[i]==1){
      c[b[i]]=1;
    }
  }
    for(j=0;j<M;j++){
      if(c[a[j]]==1 && b[j]==N){
        y++;
        break;
      }
    }
  if(y==1){
    printf("POSSIBLE");
  }else{
    printf("IMPOSSIBLE");
  }

  return 0;
}
