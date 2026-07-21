#include<stdio.h>
 
int main(){
 long int a,b,ab,tmp,r,retval;
  retval=scanf("%ld %ld",&a,&b);
  if(a>b){
    tmp=a;
    a=b;
    b=tmp;
  }
  ab=a*b;
  r=b%a;
  while(r!=0){
    b=a;
    a=r;
    r=b%a;
  }
  printf("%ld",ab/a);
  return 0;
}
