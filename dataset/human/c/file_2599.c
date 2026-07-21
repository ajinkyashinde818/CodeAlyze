#include<stdio.h>
#include<string.h>
int main(){
  char s[3];
  scanf("%s",s);
  char s1[]="abc";
  char s2[]="acb";
  char s3[]="bac";
  char s4[]="bca";
  char s5[]="cab";
  char s6[]="cba";
  if(strcmp(s,s1)==0){
    printf("Yes");
  }
  else if(strcmp(s,s2)==0){
    printf("Yes");
  }
  else if(strcmp(s,s3)==0){
    printf("Yes");
  }
  else if(strcmp(s,s4)==0){
    printf("Yes");
  }
  else if(strcmp(s,s5)==0){
    printf("Yes");
  }
  else if(strcmp(s,s6)==0){
    printf("Yes");
  }
  else{
    printf("No");
  }
  return 0;
}
