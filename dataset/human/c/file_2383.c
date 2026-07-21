#include<stdio.h>

int main(void)
{
   int i, a=0, b=0, c=0;
   char s[3];

   scanf("%s", s);

   for(i=0;i<3;i++){
      if(s[i]=='a') a++;
      else if(s[i]=='b') b++;
      else if(s[i]=='c') c++;
   }

   if((a==1)&&(b==1)&&(c==1)) printf("Yes\n");
   else printf("No\n");

   return 0;
}
