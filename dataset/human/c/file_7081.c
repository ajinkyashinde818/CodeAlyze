#include<stdio.h>
int main(void){
  
  int h,w,i,e,f;

  while(1){
    
    scanf("%d%d",&h,&w);
    
    if( h == 0 && w == 0)
      break;
    for( i = 0 ; i < h ; i++ ){
      if( i % 2 == 0){
	for( e = 0 ; e < w ; e++ ){
	  if( e % 2 == 0 )printf("#");
	  else printf(".");
	}
	printf("\n");
      }
      else {
	for( e = 0 ; e < w ; e++ ){
	  if( e % 2 == 0 )printf(".");
	  else printf("#");
	}
	printf("\n");
      }
    }
    printf("\n");
  }
  return 0;
}
