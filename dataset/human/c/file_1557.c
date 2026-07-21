#include<stdio.h>
int main(){
  char X,Y;
  scanf("%c %c",&X,&Y);
  if(X<='F'&&X>='A'&&Y<='F'&&Y>='A'){
  if(X<Y)  printf("<\n");
  else if(X>Y)  printf(">\n");
  else  printf("=\n");
  }
 return 0;
}
