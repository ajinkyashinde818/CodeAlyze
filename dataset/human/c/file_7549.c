#include <stdio.h>

int main(int argc, char *argv[]){
  int count=0;
  int input;
  scanf("%d", &input);
  while(input!=0){
    printf("Case %d: %d\n", ++count, input);
    scanf("%d", &input);
  }
  return(0);
}
