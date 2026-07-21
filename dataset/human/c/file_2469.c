#include<stdio.h>
int main(void)
{
  char s[3];
  int n;
  
  scanf("%s",s);
  if(s[0]!=s[1]){
    if(s[1]!=s[2]){
      if(s[2]!=s[0]){
      puts("Yes");
  }
  else
    puts("No");
  } 
    else
    puts("No");
  } 
  else
    puts("No");
  
      
  return(0);
  }
