#include<stdio.h>
int main(){
  int H,W,i,j;
  H>1,W<300;
  while(1){
    scanf("%d %d",&H,&W);
    if(H==0&&W==0){
      break;
    }
    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
	if((i+j)%2==0){
	  printf("#");
	}
	else{
	  printf(".");
	}
      }
      printf("\n");
    }
    printf("\n");
  }
  return(0);
}
