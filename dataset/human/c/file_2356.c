#include <stdio.h>

void swap(char *a, char *b) {
  char t;
  t = *a, *a = *b, *b = t;
}

int main(void) {
  char a[4];
  scanf("%s", a);
  if(a[0] > a[1]) swap(a, a + 1);
  if(a[0] > a[2]) swap(a, a + 2);
  if(a[1] > a[2]) swap(a + 1, a + 2);
  if(a[0] == 'a' && a[1] == 'b' && a[2] == 'c') printf("Yes");
  else printf("No");
  return 0;
}
