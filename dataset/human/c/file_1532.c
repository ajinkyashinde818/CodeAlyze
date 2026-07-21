#include<stdio.h>

int main(){

  char x,y;

  scanf("%c %c",&x,&y);

  if((int)x > (int)y){
    printf(">\n");
  }else if((int)x == (int)y){
    printf("=\n");
  }else{
    printf("<\n");
  }

  return 0;

}
