#include<stdio.h>
int main(){
  int H,W,i=0,j;
  while( scanf("%d %d",&H,&W) != EOF ){

    if(H==0 && W==0){
      break;
    }

    for(i=0 ; i<H ; i++){
      for(j=0 ; j<W ; j++){
	if(i%2 == j%2){
	  printf("#");
	}
	if(i%2 != j%2){
	  printf(".");
	}
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
