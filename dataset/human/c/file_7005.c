#include<stdio.h>
int main(){
  int H,W;
  int i,j,a;
  scanf("%d %d",&H,&W);
  while(H!=0 || W!=0){
    for(i=0; i<H; i++){
      for(j=0; j<W; j++){
	a=(i+j)%2;
	if(a==0){
	  printf("#");
	}
	else printf(".");
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d %d",&H,&W);
  }
  return(0);
}
