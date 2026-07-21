#include<stdio.h>

int main(void) {
  
  char s[3];
  scanf("%s", &s);
  
  int x = 0;
  int y = 0;
  int z = 0;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'a') x++;
    if (s[i] == 'b') y++;
    if (s[i] == 'c') z++;
  }
  
  if (x == 1 && y == 1 && z == 1) printf("Yes\n");
  else printf("No\n");
  
  return 0;
}
