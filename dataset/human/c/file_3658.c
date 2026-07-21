#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
  long long int a,b,c,r,tmp;
  scanf("%lld %lld",&a,&b);
  c = a*b;
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
 

  printf("%lld\n",c/b);

  return 0;
}
