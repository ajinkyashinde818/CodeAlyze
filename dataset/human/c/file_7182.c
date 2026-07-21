#include <stdio.h>
int main(void)
{

  int H,W,a,b,c;

  while(1){
  scanf("%d %d",&H,&W);
  if(H==0 && W==0)
      break;    
    if(H>=1&&W>=1&&H<=300&&W<=300){
 for(a=1;a<=H;a++){

    for(b=1;b<=W;b++){
      if(a%2==1){
	if(b%2==1)
	  printf("#");
	else
	  printf(".");
      }
      else{
	if(b%2!=1)
	  printf("#");
	else
	  printf(".");
      }}
    printf("\n");
 } 
 printf("\n");
}}

  return 0;
}
