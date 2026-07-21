#include<stdio.h>
main(){
  int H,W,c,d;
  while(1){
    scanf("%d %d",&H,&W);
    if(H==0 && W==0)break;
    for(c=1;c<=H;c++){
      if(c%2!=0){
    for(d=0;d<W;d++){
      printf("#");
      d=d+1;
      if(d<W){
        printf(".");
      }
    }
    printf("\n");
      }
      else{
    for(d=0;d<W;d++){
      printf(".");
      d=d+1;
      if(d<W){
        printf("#");
      }
    }
    printf("\n");
      }
    }
    printf("\n");
  }
  return 0;
}
