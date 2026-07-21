#include<stdio.h>
int main()
{
long int a,b,c,i,d,min;
  scanf("%ld %ld",&a,&b);
  d=0;
  
  if(a<b) min=a;
  else min=b;
    i=min;
  while(d==0 && i>0)
  {
  if(a%i==0 && b%i==0) {c=i;
                        d++;}
  else i--;                    
  }

  printf("%ld",a*b/c);
  
return 0;
}
