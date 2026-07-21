#include<stdio.h>
int main()
{
   char m[10];
   int i,w=0,r=0,t=0;
   gets(m);
   for(i=0;i<3;i++)
   {
       if(m[i]=='a')
         w=1;
       if(m[i]=='b')
         r=1;
       if(m[i]=='c')
         t=1;
   }
   if(w==1&&t==1&&r==1)
      printf("Yes\n");
   else
    printf("No\n");
   return 0;
}
