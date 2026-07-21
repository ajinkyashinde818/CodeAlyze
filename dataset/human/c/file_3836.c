#include<stdio.h>
long gcd(int a, int b) //ユークリッドの互除法による最小公倍数算出 (a>=b)
{
  long A=a, B=b, temp;
  while(a%b!=0){
    temp=a%b;
    a=b;
    b=temp;
  }
  return b*(A/b)*(B/b);
}

int main()
{
  int A,B;
  scanf("%d %d",&A,&B);
  
  long ans;
  if(A>B){
    ans = gcd(A,B);
  }else{
    ans = gcd(B,A);
  }
  printf("%ld",ans);
}
