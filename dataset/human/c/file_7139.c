#include<stdio.h>

int main(void){
  int i,j,k,num;
  int H[100000]={0},W[100000]={0};

  for(i=0;;i++){
    scanf("%d%d",&H[i],&W[i]);
    if(H[i]==0 && W[i]==0)  break;
  }
  num=i;
  for(i=0;i<num;i++){
    for(j=0;j<H[i];j++){
      for(k=0;k<W[i];k++){
        if((j+k)%2==0)  printf("#");
        else            printf(".");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
