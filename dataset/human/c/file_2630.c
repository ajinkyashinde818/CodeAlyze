#include<stdio.h>

int main(void)
{
   char s[3];
   int i, a[2];

   scanf("%s", s);
   for(i=0;i<3;i++){
      if(s[i] == 'a')
         a[i] = 1;
      else if(s[i] == 'b')
         a[i] = 2;
      else if(s[i] == 'c')
         a[i] = 3;
      else a[i] = 0;
}
      if (a[0] * a[1] * a[2] == 6){
           printf("Yes\n");
}
      else printf("No\n");

   return 0;
}
