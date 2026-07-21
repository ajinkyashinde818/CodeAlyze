#include<stdio.h>

int main(){
  char X[2], Y[2];
  
  scanf("%s %s", X, Y);
  
  if(X[0] > Y[0]){
    printf(">\n");
  } else if(X[0] == Y[0]){
    printf("=\n");
  } else {
    printf("<\n");
  }
  
  return 0;
}
