#include <stdio.h>

int main(void)
{
   char s[4];
   int i,a,b,ca=0,cb=0,cc=0;

   scanf("%s",s);

   if((s[0]==s[1])||(s[0]==s[2])||(s[1]==s[2]))
      printf("No");

   else printf("Yes");

   return 0;
}
