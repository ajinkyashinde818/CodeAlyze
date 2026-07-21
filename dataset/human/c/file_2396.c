#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i;
   char a[3];
   scanf("%s",a);
   int j=0,k=0,l=0;
   for(i=0;i<3;i++)
   {
       if(a[i]=='a')
        j=1;
       if(a[i]=='b')
        k=1;
       if(a[i]=='c')
        l=1;
   }
   if(j==1&&k==1&&l==1)
    printf("Yes\n");
   else
    printf("No\n");
    return 0;
}
