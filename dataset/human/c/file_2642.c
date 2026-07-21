#include <stdio.h>
int main()
{
  char a[3];
  int i,b=0,c=0,d=0;
  
  scanf("%s",a);
  
  for(i=0;i<3;i++){
   if(a[i]=='a')  b++;
      else if (a[i]=='b')  c++;
         else if (a[i]=='c')  d++;
  }
 
  if(b==1&&c==1&&d==1)
       printf("Yes\n");
     else printf("No\n");           
  return 0;
}
