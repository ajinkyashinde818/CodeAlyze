//abc148E
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int i;
  long long n=0, tmp=10, mp5=1, cou=0, sum=0;
  //N,tmp:10*5^X,mp5:N=tmpのときの0の個数,cou:X,sum:Nのときの0の個数計測
  scanf(" %lld", &n);

  if(n % 2 == 1) printf("0");//奇数なら0
  else{
    while(tmp < n)
      tmp*=5, mp5=mp5 * 5 + 1, cou++;//10を5倍するごとに10の倍数はX*5+1倍
    for(i=cou; i >= 0; i--){
      if(n >= tmp) sum+=(n / tmp) * mp5, n%=tmp;//a*10*5^Xのときの0の個数を計上、n-a*10*5^X
      mp5=(mp5 - 1) / 5, tmp/=5;//a*10*5^(X-1)のときの0の個数に変更、tmp=a*10*5^X
    }
    printf("%lld", sum);
  }
  return 0;
}
