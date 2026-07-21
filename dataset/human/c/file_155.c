#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  int i;
  int sizeS=0;
  int flag=0;
  int temp=3;
  if(N==2){
    printf("No");
    return 0;
  }
  if(N==1){
    printf("Yes\n");
    printf("2\n");
    printf("1 1\n");
    printf("1 1\n");
    return 0;
  }
  if(N==3){
    sizeS=3;
    flag=1;
  }
  if(N>3){
    for(i=3;i<500;i++){
      temp=temp+i;
      if(temp==N){
        sizeS=i+1;
        flag=1;
      }
    }
  }
  if(flag==0){
    printf("No");
    return 0;
  }
  int j;
  int S[sizeS+1][sizeS+1];
  S[1][1]=1;
  S[2][1]=1;
  int K=1;
  for(i=2;i<sizeS;i++){
    for(j=1;j<=i;j++){
      S[j][i]=K+j;
    }
    for(j=1;j<=i;j++){
      S[i+1][j]=K+j;
    }
    K=K+i;
  }

  printf("Yes");
  printf("\n");
  printf("%d\n",sizeS);
  for(i=1;i<=sizeS;i++){
    printf("%d ",sizeS-1);
    for(j=1;j<=sizeS-1;j++){
      printf("%d ",S[i][j]);
    }
    printf("\n");
  }
  return 0;
}
