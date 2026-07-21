#include<stdio.h>
int main()
{
 char s[3];

 
  
 scanf("%s",&s);

 if(s[0]=='a'){
  if((s[1]=='b'&&s[2]=='c')||(s[1]=='c'&&s[2]=='b')){
    printf("Yes");
  }
   else printf("No");
 }
    if(s[0]=='b'){
  if((s[1]=='a'&&s[2]=='c')||(s[1]=='c'&&s[2]=='a')){
    printf("Yes");
  }
      else printf("No");
 } 
  if(s[0]=='c'){
  if((s[1]=='a'&&s[2]=='b')||(s[1]=='b'&&s[2]=='a')){
    printf("Yes");
  }
   else printf("No");
 }
   return 0;
}
