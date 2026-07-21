#include<stdio.h>
main(){
  int H,W,i,j,flg=0  ;
  while(1){
  scanf("%d %d",&H,&W);
  if(H==0&&W==0)break;
  for(i=1;i<=H;i++){
    flg=i;
    for(j=1;j<=W;j++){
      if(flg%2==1){printf("#");flg++;}
      else{printf(".");flg++;}
    }
    printf("\n");
    }
  printf("\n");
}
  return 0;
}
