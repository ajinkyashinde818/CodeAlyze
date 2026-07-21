#include<stdio.h>
int main()
{
  char s[3];
  
  scanf("%s %s %s",&s[0],&s[1],&s[2]);
  
  if(s[0]!=s[1]){
    if(s[1]!=s[2]){
      if(s[2]!=s[0]){
        printf("Yes");
      }else
        printf("No");
    }else
      printf("No");
  }else
    printf("No");
  
  return 0;
}
