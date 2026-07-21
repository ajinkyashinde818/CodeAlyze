#include<stdio.h>
int main(void)
{
    char s[3];
    
   scanf("%s", s);
  
   if(s[0] == 'a' || s[0] == 'b' || s[0] == 'c' ){
     if(s[1] != s[0]){
        if(s[1] == 'a' || s[1] == 'b' || s[1] == 'c' ){
           if(s[2] != s[0] && s[2] != s[1]){        
               if(s[2] == 'a' || s[2] == 'b' || s[2] == 'c' ){
                         puts("Yes");
               }
               else puts("No");
           }
           else puts("No");
        }
        else puts("No");
     }
     else puts("No");
   }
   else puts("No");
  return 0;
}
