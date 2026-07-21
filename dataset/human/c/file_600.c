#include <stdio.h>

int main(void){
  int N,M,i,j,k,l,flag;
  char a[51][51],b[51][51];

  scanf("%d %d",&N,&M);

  for(i=0;i<N;i++){
    scanf("%s",a[i]);
  }
  for(i=0;i<M;i++){
    scanf("%s",b[i]);
  }

  for(i=0;i<N-M+1;i++){
    for(j=0;j<N-M+1;j++){
      flag=1;
      for(k=0;k<M;k++){
        for(l=0;l<M;l++){
          if(a[i+k][j+l]!=b[k][l]){
            flag=0;
          }
        }
      }
      if(flag==1){
        printf("Yes\n");
        return 0;
      }
    }
  }

  if(flag==0){
    printf("No\n");
  }

  return 0;
}
