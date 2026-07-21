#include <stdio.h>

int main() {
  char character_x, character_y;
  scanf("%c %c", &character_x, &character_y);
  if(character_x > character_y) {
    printf(">\n");
  } else if(character_x < character_y) {
    printf("<\n");
  } else {
    printf("=\n");
  }
  return 0;
}
