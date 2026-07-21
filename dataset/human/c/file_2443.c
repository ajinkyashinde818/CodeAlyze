#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[5];
  char a[5] = "abc";
  char b[5] = "acb";
  char c[5] = "bac";
  char d[5] = "bca";
  char e[5] = "cab";
  char f[5] = "cba";
	scanf("%s", s);

  if (strcmp (s, a) == 0 || strcmp (s, b) == 0 || strcmp (s, c) == 0 || strcmp (s, d) == 0 || strcmp (s, e) == 0 || strcmp (s, f) == 0) {
    printf("Yes\n");
  } else {
  printf("No\n");
  }

return 0;
}
