#include<stdio.h>
#include<string.h>
long long gcd(int,int);

int main(){
  long int a,b ; scanf("%ld%ld",&a,&b);
  long long g= gcd(a,b);
  printf("%lld\n",a*b/g);
  return 0;
}

long long gcd(int x,int y){
  int p;
  p=x%y;
  if(p==1) return 1;
  else if(p==0) return y;
  else  return gcd(y,p);
}
