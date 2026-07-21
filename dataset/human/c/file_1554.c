#include <stdio.h>
#include <string.h>
int main(void){
char a[5],b[5];
  int k;
  scanf("%s %s",&a,&b);
  k=strcmp(a,b);
  if(k<0){printf("<");}
  if(k==0){printf("=");}
  if(k>0){printf(">");}
return 0;
}
