#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
   char input[4];
   int a=0;
   scanf("%s",input);
   a += (strcmp("abc",input)==0)?1:0;
   a += (strcmp("acb",input)==0)?1:0;
   a += (strcmp("bac",input)==0)?1:0;
   a += (strcmp("bca",input)==0)?1:0;
   a += (strcmp("cab",input)==0)?1:0;
   a += (strcmp("cba",input)==0)?1:0;
   if (a==1){printf("Yes\n");}else{printf("No\n");}
  return 0;
}
