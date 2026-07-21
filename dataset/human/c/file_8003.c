#include <stdio.h>
#include <math.h>

void swap(long long *xp, long long *yp) {
  long long temp = *xp; 
  *xp = *yp; 
  *yp = temp; 
} 

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(&a, &b);
    u -= t * v; swap(&u, &v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main(void) {
  int X, Y;
  scanf("%d %d", &X, &Y);
  if ((Y * 2 - X) % 3 != 0 || (X * 2 - Y) % 3 != 0 || Y * 2 - X < 0 || X * 2 - Y < 0) {
    printf("0\n");
    return 0;
  }

  int v = (Y * 2 - X) / 3;
  int h = (X * 2 - Y) / 3;

  long long result = 1;
  for (int i = v + 1; i <= v + h; i++) {
    result *= i;
    result %= 1000000007;
  }
  for (int i = 2; i <= h; i++) {
    result = result * modinv(i, 1000000007) % 1000000007;
  }

  printf("%lld\n", result);
}
