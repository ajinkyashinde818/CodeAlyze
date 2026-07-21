#include <stdio.h>

main(void)
{
  char abc[4];
  
  scanf("%s",abc);
  
 if(abc[0]!=abc[1])
 {
   if(abc[1]!=abc[2])
   {
     if(abc[0]!=abc[2])
     {
       printf("Yes");
     }
     else
       printf("No");
   }
   else
     printf("No");
 }
  else
    printf("No");
  
  return 0;
}
