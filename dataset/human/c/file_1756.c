#include<stdio.h>
int main(void){
  int l,i,j,sum=0,ban;
  scanf("%d",&l);
  int num[3+1][l+1];
  for(i=1;i<=3;i++){
    for(j=1;j<=l;j++){
      scanf("%d",&num[i][j]);
      if(i==3&&j==l-1){
        break;
      }
    }
  }
  for(i=1;i<=l;i++){
    ban=num[1][i];
    sum+=num[2][ban];
    if(num[1][i]+1==num[1][i+1]){
      sum+=num[3][ban];
    }
  }
  printf("%d",sum);
  return 0;
}
