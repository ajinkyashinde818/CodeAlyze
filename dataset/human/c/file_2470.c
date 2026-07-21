#include"stdio.h"
int main(){
  char s[3];
  scanf("%s",s);
  int a=0;
  if(s[0]=='a'&&s[1]=='b'&&s[2]=='c')
    a=1;
    if(s[0]=='a'&&s[1]=='c'&&s[2]=='b')
      a=1;
  if(s[0]=='b'&&s[1]=='a'&&s[2]=='c')
    a=1;
  if(s[0]=='b'&&s[1]=='c'&&s[2]=='a')
    a=1;
    if(s[0]=='c'&&s[1]=='a'&&s[2]=='b')
      a=1;
       if(s[0]=='c'&&s[1]=='b'&&s[2]=='a')
         a=1;
  if(a)printf("Yes");
  else printf("No");
  
  
    
  
  
  
  
  return 0;
}
