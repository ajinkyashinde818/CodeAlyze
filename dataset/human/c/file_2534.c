#include<stdio.h>
int main(void){
  int i,p=0;
  char s[3];
  
  for(i=0;i<3;i++)scanf("%s",s);
  
  
    if(s[0]=='a'){
    if((s[1]=='b'&&s[2]=='c')||(s[1]=='c'&&s[2]=='b'))
      p+=1;
    }
    
  if(s[0]=='b'){
    if((s[1]=='a'&&s[2]=='c')||(s[1]=='c'&&s[2]=='a'))
    p+=1;
  }
  
  if(s[0]=='c'){
       if((s[1]=='a'&&s[2]=='b')||(s[1]=='b'&&s[2]=='a'))
    p+=1;
  }
  
  if(p)printf("Yes");
    else printf("No");
  

return 0;
}
