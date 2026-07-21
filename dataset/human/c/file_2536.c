#include<stdio.h>
#include<string.h>
int main(void){
 char s[5];
 char *s1="abc";
 char *s2="acb";
 char *s3="bac";
 char *s4="bca";
 char *s5="cab";
 char *s6="cba";
 scanf("%s",s);

 if(strcmp(s,s1)==0){
   puts("Yes");
   return 0;
 }
 if(strcmp(s,s2)==0){
   puts("Yes");
   return 0;
 }
 if(strcmp(s,s3)==0){
   puts("Yes");
   return 0;
 }
 if(strcmp(s,s4)==0){
   puts("Yes");
   return 0;
 }
 if(strcmp(s,s5)==0){
   puts("Yes");
   return 0;
 }
 if(strcmp(s,s6)==0){
   puts("Yes");
   return 0;
 }
 puts("No");
 return 0;
}
