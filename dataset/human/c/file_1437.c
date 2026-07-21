#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "unistd.h"
#include "string.h"
#include <math.h>
int ans;
int main(int argc, char* argv[]){
  long int a,b,c;
  scanf("%ld",&a);
  if (a/10==9||a-(a/10)*10==9) {
    printf("Yes");
  }else{
    printf("No\n" );
  }
}
