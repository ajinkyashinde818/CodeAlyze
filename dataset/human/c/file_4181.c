#include <stdio.h>

int yakusuu(int a, int b)
{
  while(1) {
    if (a > b) {
      a %= b;
      if (a == 0) {
	return b;
        break;
      }
    } else {
      b %= a;
      if (b == 0) {
	return a;
        break;
      }
    }
  }
}

int main(void)
{
  int a, b, k, i;
  int count = 0;
  scanf("%d %d %d", &a, &b, &k);
  for (i = yakusuu(a, b); i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
      count++;
      if (count == k)
	break;
    }
  }
  printf("%d\n", i);
}
