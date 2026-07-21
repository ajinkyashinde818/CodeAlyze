#include<stdio.h>
main(){
  int H,W,i,j;
  while(1){
    scanf("%d %d",&H,&W);
  if(H==0,W==0){
    break;
  }
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if((i%2==1 && j%2==1) || (i%2==0 && j%2==0)){
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
  return 0;
}
