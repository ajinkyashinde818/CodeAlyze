#include <stdio.h>
#include <math.h>

long modpow(long a, long n, long mod){
  long size;
  for (long i = 1; ; i++) {
    if (pow(2,i) > n) {
      size = i;
      break;
    }
  }
  long bit[size];
  bit[0] = n;
  for (long i = 1; i < size; i++) {
    bit[i] = bit[i-1]/2;
    bit[i-1] %= 2;
  }
  long powa[size];
  powa[0] = a;
  for (long i = 1; i < size; i++) {
    powa[i] = powa[i-1]*powa[i-1];
    powa[i] %= mod;
  }
  long answer = 1;
  for (long i = 0; i < size; i++) {
    if (bit[i] == 1) {
      answer *= bit[i]*powa[i];
      answer %= mod;
    }
  }
  return answer;
}
long modCombination(long n, long r, long mod) {
  long answer;
  if (n-r < r) {
    r = n-r;
  }
  long nu = 1;
  long de = 1;
  for (long i = 1; i <= r; i++) {
    nu *= n+1-i;
    nu %= mod;
    de *= i;
    de %= mod;
  }
  answer = nu;
  answer *= modpow(de,mod-2,mod);
  answer %= mod;
  return answer;
}

int main(void) {

  long x,y;
  scanf("%ld %ld", &x, &y);
  long mod = pow(10,9)+7;
  if ((x+y)%3 != 0) {
    printf("0\n");
    return 0;
  }
  long move = (x+y)/3;
  if (x < move || y < move) {
    printf("0\n");
    return 0;
  }
  long move_a = y-move;
  if (move_a < 0) {
    printf("0\n");
    return 0;
  }
  printf("%ld\n", modCombination(move,move_a,mod));

  return 0;
}
