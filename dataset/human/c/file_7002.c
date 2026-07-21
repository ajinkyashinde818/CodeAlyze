#include<stdio.h>
int main(){
  int h,w;
  int i,j,c;
  while(1){
    scanf(" %d %d",&h,&w);
    c=1;
    if(h==0&&w==0){
      break;
    }
      for(i=0;i<h;i++){
	for(j=0;j<w;j++){
	  if(c%2==0){
	    printf(".");
	  }else{
	    printf("#");
	  }
	  c++;
	}
	printf("\n");
	if(w%2==0){
	  c++;
	}
      }
      printf("\n");
  }
  return(0);
}
