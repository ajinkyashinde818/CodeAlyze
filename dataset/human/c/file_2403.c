#include <stdio.h>
 
int main(void)
{char str[4];
  int x=0, b=0, c=0;
  
  scanf("%s", str);
 
 if(str[0]=='a')
   x=x+1;
 if (str[1]=='a')
    x=x+1;
 if (str[2]=='a')
    x=x+1;
 
  if(str[0]=='b')
   b=b+1;
 if (str[1]=='b')
    b=b+1;
 if (str[2]=='b')
    b=b+1;
 
  if(str[0]=='c')
   c=c+1;
 if (str[1]=='c')
    c=c+1;
 if (str[2]=='c')
    c=c+1;
 
 if(x==1 &&b==1&&c==1)
   printf("Yes");
 else
   printf("No");
 
  return 0;
}
