#include<stdio.h>
int main(void)
{
 int a,b,c,d;
 int ab,cd;

 scanf("%d%d%d%d",&a,&b,&c,&d);

 ab = a * b;
 cd = c * d;

 if(ab < cd)
  {
   printf("%d",cd);
  }

 if(ab > cd)
  {
   printf("%d",ab);
  }

 if(ab == cd)
  {
   printf("%d",ab);
  }

 return 0;
}
