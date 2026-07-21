#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define rep(i,n) for(int i=0; i <(n); i++)
int main(){
  char a[100];
  char b[100];
  scanf("%s%s",a,b);
  if(strcmp(a,b)>0){
    printf(">\n");
  }else if(strcmp(a,b)==0){
    printf("=\n");
  }else{
    printf("<\n");
  }
  return 0;
}
