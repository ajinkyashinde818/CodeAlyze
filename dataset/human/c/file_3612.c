#include <stdio.h>
 
int main(void)
{
 
  long a, b;
  scanf("%ld %ld", &a,&b);

  long x = a * b;
 

 int tmp;

  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  int r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
  printf("%ld", x/b);
 
  return 0;
}
