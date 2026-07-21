#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "unistd.h"
#include "string.h"
#include <math.h>
int main(int argc, char* argv[]){
  long int a=0,b=0,c=0,ans=0;
  char s[7];

  scanf("%ld %ld",&a,&b);
  long int d[b],e[b];
  for (int i = 0; i < b; i++) {
    scanf("%ld",&d[i]);
    e[i]=d[i];
  }
  for (int i = 1; i < b; i++) {
    e[i]=d[i]-d[i-1];
  }
  e[0]=a-d[b-1]+d[0];
  long int max=0,l=0;
  for (int i = 0; i < b; i++) {
    if (e[i]>max) {
      max=e[i];
      l=i;
    }
  }
  if (l!=0) {
    printf("%d",a-d[l]+d[l-1]);
  }else{
    printf("%d",d[b-1]-d[0]);
  }
}
