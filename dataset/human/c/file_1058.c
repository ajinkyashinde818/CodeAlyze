#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  char s[50];
  int i, l;
  scanf("%s",s);
  l = strlen(s);
  for(i=0;i<l-8;i++) printf("%c",s[i]);
  printf("\n");
  return 0;
}
