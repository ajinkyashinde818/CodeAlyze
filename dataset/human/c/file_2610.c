#include <stdio.h>

int main() {
  char s[4];
  scanf("%s", s);
  long x = (long)s[0] * (long)s[1] * (long)s[2];
  long y = (long)'a' * (long)'b' * (long)'c';
  
  if (x == y) printf("Yes\n");
  else printf("No\n");
  
  return 0;
}
