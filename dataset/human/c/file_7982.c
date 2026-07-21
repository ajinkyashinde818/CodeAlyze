#include<stdio.h>
#include<math.h>
#define X 1000000007
long fact[2000001] = {};
long invfact[2000001] = {};

long pow_(long a,long n){
  long ans = 1;
  while(n>0){
    if(n & 1){
      ans = (ans * a) % X;
    }
    a = (a * a) % X;
    n >>= 1;
  }
  return ans ;
}
  
void makefact(){
  long i = 1;
  for(i=1;i<=2000000;i++){
    if(i==1){
      fact[i] = 1;
      invfact[i] = 1;
    }else{
      fact[i] = (fact[i-1] * i) % X;
      invfact[i] = pow_(fact[i],X-2) % X;
    }
  }
}

int main(){
  long x = 0;
  long y = 0;
  long movea = 0;
  long moveb = 0;
  long i = 0;
  long j = 0;
  long oh = 0;
  long flag = 0;
  
  scanf("%ld %ld",&x,&y);
  makefact();
  for(i = 0;i < x/2+1;i++){
    movea = x - 2 * i;
    moveb = i;
    if(2*movea + moveb == y){
      flag = 1;
      break;
    }
  }
  if(!flag){
    oh = 0;
  }else{
    if(movea == 0 || moveb == 0){
      oh = 1;
    }else{
      oh = (((fact[movea+moveb]*invfact[movea])%X)*invfact[moveb]) % X;
    }
  }

  printf("%ld",oh);
  return 0;
}
