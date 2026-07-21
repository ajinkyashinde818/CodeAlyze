#include<stdio.h>
int main(void){
  int H,W;
  int i,j;
  while(1){
    scanf("%d %d",&H,&W);
    if(H==0 && W==0)
      break;
    for(i=1;i<=H;i++){
      if(i%2==1){
	for(j=1;j<=W;j++){
	  if(j%2==1)
	    printf("#");
	  else 
	    printf(".");
	}
	printf("\n");
      }
      if(i%2==0){
	for(j=1;j<=W;j++){
	  if(j%2==1)
	    printf(".");
	  else
	    printf("#");
	}
	printf("\n");
      }
    }
    printf("\n");
  }
  return 0;
}
