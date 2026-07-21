#include<stdio.h>

int main (void){
  int H=1,W,i,j;
  while(scanf("%d %d",&H,&W),H!=0 || W!=0){
    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
        if((i+j)%2){
          printf(".");
        }else{
          printf("#");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
