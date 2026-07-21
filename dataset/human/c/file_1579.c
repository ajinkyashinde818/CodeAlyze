#include <stdio.h>
#include <string.h>

int main(){
   char X[2],Y[2];
  scanf("%s %s",X,Y);
  if(strcmp(X,Y)==0){
    printf("=");
  }
  if(strcmp(X,Y)<0){
    printf("<");
  }
  if (strcmp(X,Y)>0) {
    printf(">");
  }
  return 0;
}
