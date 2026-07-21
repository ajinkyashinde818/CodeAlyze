#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  long int A,B,a,b,tmp;
  char str[20];
  
  fgets(str,sizeof(str),stdin);
  A=atol(strtok(str," "));
  B=atol(strtok(NULL," "));
  
  if(B>A){
    tmp=B;
    B=A;
    A=tmp;
  }
    
  
  a=A;
  b=B;
  while(a%b!=0){
    tmp=a%b;
    a=b;
    b=tmp;
  }
  printf("%ld\n",A*B/b);
  return 0;
}
