#include<stdio.h>
#include<string.h>
 
int main(){
  long a, b, r, x, tmp, e;
 
 
  e = scanf("%ld %ld", &a, &b);
 
  if (e==-1)
  {
    printf("%ld %ld",a,b);
  }
  
  x = a * b;
 
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
  printf("%ld", x/b);
 
  return 0;
 
}
