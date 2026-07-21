#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

int main(){
  ll n;
  ll i;
  ll cnt = 0;

  scanf("%lld", &n);

  if(n % 2 == 1){
    printf("0\n");
    return 0;
  }

  i = 5;
  while(n > i){
    cnt += n/(i*2);
    i = i*5;
  }

  printf("%lld\n", cnt);

  return 0;
}
