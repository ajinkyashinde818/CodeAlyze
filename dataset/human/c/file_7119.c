#include<stdio.h>
 
int main(void) {
  int H,W,i,j;
  while(scanf("%d %d",&H,&W)){
    if(H==0&&W==0) break;
    for(i=1;i<=H;i++){
      for(j=1;j<=W;j++)
    if((i+j)%2==0)
      printf("#");
    else
      printf(".");
      printf("\n");
    }
    printf("\n");
  }
  return(0);
}
