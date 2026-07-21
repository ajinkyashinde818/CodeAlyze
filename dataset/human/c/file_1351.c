#include <stdio.h>

int main(){
  int n,m,i,x=0;
  scanf("%d %d",&n,&m);
  int a[200001],b[200001],c[200001];
  for(i=0;i<m;i++){
    scanf("%d %d",&a[i],&b[i]);
  }
  for(i=0;i<m;i++){
    c[i]=0;
  }
  for(i=0;i<m;i++){
    if(a[i]==1){
      c[b[i]]=1;
    }
  }
  for(i=0;i<m;i++){
    if(c[a[i]]==1 && b[i]==n){
      x += 1;
      break;
    }
  }
  if(x==1){
    printf("POSSIBLE");
  }else{
    printf("IMPOSSIBLE");
  }
  return 0;
}
