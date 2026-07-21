#include<stdio.h>

int main(){
  int h,w,i,j;

  while(1){
    scanf("%d%d",&h,&w);

    if(!h&&!w)
      return 0;

    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if((i+j)%2==0)
	  printf("#");
	else
	  printf(".");
      }
      printf("\n");
    }      
    printf("\n");
  }
}
