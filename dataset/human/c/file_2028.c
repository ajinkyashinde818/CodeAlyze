#include <stdio.h>

int main(void)
{

  int a, b, c;

  scanf("%d%d%d", &a, &b, &c);

  if (c < a + b)
  {
    printf("%d\n", b + c);
  }
  else if (c == a + b)
  {
    printf("%d\n", b + c);
  }
  else
  {
    printf("%d\n", b + a + b + 1);
  }

  return 0;
}
