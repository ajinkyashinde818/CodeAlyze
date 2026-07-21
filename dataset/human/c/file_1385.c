#include<stdio.h>
int main(){
  int N,M,i;
  scanf("%d %d",&N,&M);
  int a[M],b[M],c[200000],d[200000];
  for(i=0;i<200000;i++){
    c[i]=0;
    d[i]=0;
  }
  for(i=0;i<M;i++){
    scanf("%d %d",&a[i],&b[i]);
  }
  for(i=0;i<M;i++){
    if(a[i]==1){
      c[b[i]]=1;
    }
    if(b[i]==N){
      d[a[i]]=1;
    }
  }
  for(i=0;i<200000;i++){
    if(d[i]==1 && c[i]==1){
      printf("POSSIBLE");
      return 0;    
    }
  }
  printf("IMPOSSIBLE");
  return 0;
}
