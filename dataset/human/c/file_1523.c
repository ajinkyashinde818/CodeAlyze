#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "unistd.h"
#include "string.h"
#include <math.h>
int ans;
int main(int argc, char* argv[]){
  int a,b,c;
  scanf("%x %x",&a,&b);
  if (a>b) {
    printf(">" );
  }else if(a<b){
    printf("<");
  }else{
    printf("=" );
  }
}
