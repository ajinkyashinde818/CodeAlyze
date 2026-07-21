#include<stdio.h>

int main()
{
  int a,b,k;

  scanf("%d %d %d", &a, &b, &k);

  int cnt = 0;
  int i;
  
  for (i = a; i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
      cnt++;
    }

    if (cnt == k) {
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}
