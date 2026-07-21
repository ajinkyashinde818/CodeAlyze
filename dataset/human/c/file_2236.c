#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[500001];
  char *p1 = &s[200000];
  scanf("%s", p1);
  char *p2 = p1 + strlen(p1);
  int q;
  scanf("%d", &q);
  int flag = 1;
  for (int i = 0; i < q; i++) {
    int n, f;
    char c;
    scanf("%d", &n);
    if (n == 1) {
      flag = 1 - flag;
      continue;
    }
    scanf("%d %c", &f, &c);
    if (flag ^ --f) {
      *--p1 = c;
    } else {
      *p2++ = c;
    }
  }
  *p2 = '\0';
  if (flag) {
    puts(p1);
  } else {
    while (--p2 >= p1) {
      putchar(*p2);
    }
    putchar('\n');
  }
}
