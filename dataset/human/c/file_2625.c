#include <stdio.h>
#include<string.h>
int main()
{
   long int k,b,c,i;
   char a[100];
   gets(a);
   k=b=c=0;
   for(i=0;i<strlen(a);i++)
   {
       if(a[i]=='a')
       {
           k=1;
       }
       if(a[i]=='b')
       {
           b=1;
       }
       if(a[i]=='c')
       {
           c=1;
       }
   }
if(k==1 && b==1 && c==1)
{
    printf("Yes");
}else{
    printf("No");
}
  
     return 0;
}
