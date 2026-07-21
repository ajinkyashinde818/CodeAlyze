#include <stdio.h>

int main(void) {
  char c[3];
  int r[3];
  int a = 0;
  int re = 1;
  int i;
  for(i = 0; i < 3; i++) r[i] = 0;
  scanf("%c%c%c", &c[0], &c[1], &c[2]);
  for(i = 0; i < 3; i++) {
    if(c[i] == 'a') r[0] = 1;
    if(c[i] == 'b') r[1] = 1;
    if(c[i] == 'c') r[2] = 1;
  }
  for(i = 0; i < 3; i++) if(r[i] == 0) re = 0;
  if(re == 1) printf("Yes\n");
  else printf("No\n");
  return 0;
}
