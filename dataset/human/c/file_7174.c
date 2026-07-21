#include<stdio.h>
main(){
  int h,w,a,b;
  while(1){
    scanf("%d %d",&h,&w);
    if(h==0 && w==0)break;
    for(a=0;a<h;a++){
      for(b=0;b<w;b++){
	if(a%2==0 && b%2==0 || a%2!=0 && b%2!=0){
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
