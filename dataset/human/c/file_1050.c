#include <stdio.h>

int main(void){
  char s[51] = { '\0' };
  scanf("%s", s);
  int i = 0;
  while(s[i] != '\0') i++;
  i -= 8;
  for(int j = 0; j < i; j++) printf("%c", s[j]);
  printf("\n");

  return 0;
}
