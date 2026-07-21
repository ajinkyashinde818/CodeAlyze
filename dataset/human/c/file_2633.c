#include<stdio.h>
int main(void)
{
  int judge=0;
  char s[3];
  
  scanf("%s",s);
 
  if(s[0]=='a'){
    if(s[1]=='b'){
      if(s[2]=='c')
        judge=1;
    }else if(s[1]=='c'){
      if(s[2]=='b')
        judge=1;
    }
  }else if(s[0]=='b'){
    if(s[1]=='a'){
      if(s[2]=='c')
        judge=1;
    }else if(s[1]=='c'){
      if(s[2]=='a')
        judge=1;
    }
  }else if(s[0]=='c'){
    if(s[1]=='b'){
      if(s[2]=='a')
        judge=1;
    }else if(s[1]=='a'){
      if(s[2]=='b')
        judge=1;
    }
  }
  if(judge==0)
    puts("No");
  else if(judge==1)
    puts("Yes");
  return 0;
}
