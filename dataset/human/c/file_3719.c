#include <stdio.h>

int main(){
  long long int A,B;
  scanf("%lld %lld",&A,&B);
  long long int OA=A,OB=B;
  long long int R=A%B;
  while(R>0){
    A=B;
    B=R;
    R=A%B;
  }
  printf("%lld\n",OA*OB/B);
  return 0;
}
