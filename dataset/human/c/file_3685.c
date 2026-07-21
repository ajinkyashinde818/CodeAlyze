#include<stdio.h>
int main(void){
  long int a,b;
  scanf("%ld %ld",&a,&b);
  long int x = a*b;
  if(a < b) {
    long int tmp = a;
    a = b;
    b = tmp;
  }
  long int r = a%b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  printf("%ld\n",x/b);
  return 0;
}
