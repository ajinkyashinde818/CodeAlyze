#include<stdio.h>
main(){
  int w,h,j,i;
  scanf("%d %d",&h,&w);
  while(h!=0 || w!=0){
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
	if((i%2==1 && j%2==0) || (i%2==0 && j%2==1)){
	  printf(".");
	}
	else{
	  printf("#");
	}
	
      }
      printf("\n");
    }
    printf("\n");
    scanf("%d %d",&h,&w);
  }
  return 0;
}
