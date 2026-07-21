#include <stdio.h>

int main(void)
{
   char s[3] ;
   int i , a=0 , b=0 , c=0 ;

   scanf("%s",s);

   if((s[0]!=s[1])&&(s[1]!=s[2])&&(s[2]!=s[0]))
      printf("Yes\n");
   else
      printf("No\n");

   return 0 ;
}
