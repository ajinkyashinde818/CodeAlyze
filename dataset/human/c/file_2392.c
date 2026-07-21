#include<stdio.h>
int main(void){
  char s[3];
  scanf("%s",s);
  if(s[0]=='a'){
    if(s[1]=='b'&&s[2]=='c')
      puts("Yes");
    else if(s[1]=='c'&&s[2]=='b')
      puts("Yes");
    else
      puts("No");
  }
  if(s[0]=='b'){
    if(s[1]=='a'&&s[2]=='c')
      puts("Yes");
    else if(s[1]=='c'&&s[2]=='a')
      puts("Yes");
    else
      puts("No");
  }
  if(s[0]=='c'){
    if(s[1]=='b'&&s[2]=='a')
      puts("Yes");
    else if(s[1]=='a'&&s[2]=='b')
      puts("Yes");
    else
      puts("No");
  }
  return 0;
  }
