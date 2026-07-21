#include <stdio.h>

int main(void) {
  int e, y;
  scanf("%d%d", &e, &y);
  if(!e) {
    if(y < 1912) printf("M%d\n", y - 1867);
    else if(y < 1926) printf("T%d\n", y - 1911);
    else if(y < 1989) printf("S%d\n", y - 1925);
    else printf("H%d\n", y - 1988);
  } else if(e == 1) printf("%d\n", y + 1867);
  else if(e == 2) printf("%d\n", y + 1911);
  else if(e == 3) printf("%d\n", y + 1925);
  else printf("%d\n", y + 1988);
  return 0;
}
