#include<stdio.h>

int gcd(long a,long b);

int main()
{
  long A,B;
  long g,ans;

  scanf("%ld",&A);
  scanf("%ld",&B);

  if(A > B){
    g = gcd(A,B);
  }
  else{
    g = gcd(B,A);
  }
 
  ans = (A*B)/g;

  printf("%ld",ans);

}

int gcd(long a,long b){
  int s;
  while(a%b != 0){
    s = b;
    b = a%b;
    a = s;
  }
    
  return b;
}
