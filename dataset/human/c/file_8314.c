#include <stdio.h>

int main()
{
  int n, s[10], k, display;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    s[i] = getchar();
  }
  scanf("%d", &k);
  display = s[k - 1];
  for (int i = 0; i < n; i++) {
    if (s[i] == display) {
      putchar(s[i]);
    } else {
      putchar('*');
    }
  }
  puts("");
  return 0;
}
