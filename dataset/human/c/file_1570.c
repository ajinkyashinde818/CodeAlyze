#include <stdio.h>
 
int main(int argc, char *argv[]) {
  char first, second;
  scanf("%c %c", &first, &second);
  if (first < second){
    printf("<");
  }
  else if(first == second){
    printf("=");
  }
  else{
  printf(">");
  }
  return 0;
}
