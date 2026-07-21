#include <stdio.h>
main(){
  int H,W,a,b;
  while(1){
    scanf("%d %d",&H,&W);
    if(H==0 && W==0)break;
    for(a=0;a<H;a++){
      for(b=0;b<W;b++){     
	if((a%2==0 && b%2==0 || a%2==1 && b%2==1)){
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
