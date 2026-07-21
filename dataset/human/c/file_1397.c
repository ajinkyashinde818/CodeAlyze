#include<stdio.h>
    int main(){
    int N,M,c,d,i;
    int a[200001]={0},b[200001]={0};
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++){
    scanf("%d%d",&c,&d);
      if(c==1){
      a[d]=1;
      }
      if(d==N){
      b[c]=1;
      }
    }
    for(i=0;i<N;i++){
      if(a[i]==1){
        if(b[i]==1){
        printf("POSSIBLE\n");
        return 0;
        }
      }
    }
    printf("IMPOSSIBLE\n");
    return 0;
    }
