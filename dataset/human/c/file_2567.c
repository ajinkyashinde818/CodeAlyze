#include<stdio.h>
int main(){
   char s[4];
   scanf("%s",s);
   if(strcmp(s,"abc")==0||strcmp(s,"acb")==0||strcmp(s,"bac")==0||strcmp(s,"bca")==0||strcmp(s,"cab")==0||strcmp(s,"cba")==0){
   printf("Yes\n");
   }else{
   printf("No\n");
   }
   return 0;
}
