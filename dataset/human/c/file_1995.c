#include<stdio.h>
#include<stdlib.h>

int main(void){
  int a, b, c;
  int total=0;

  scanf("%d %d %d", &a, &b, &c);
  while((a+b+1) < c){
    c -= 1;
  }
  total = b + c;
  printf("%d\n", total);
  return 0;
}
