#include <stdio.h>

int main() {
  int i, number, k;
  char special_char;
  scanf("%d", &number);
  char str[number + 1];
  scanf("%s", str);
  scanf("%d", &k);
  special_char = str[k - 1];
  for(i = 0; i < number; i++) {
    if(str[i] == special_char) {
      printf("%c", str[i]);
    } else {
      printf("*");
    }
  }
  printf("\n");
  return 0;
}
