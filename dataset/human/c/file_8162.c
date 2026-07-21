#include <stdio.h>

int main() {
  int line_height_a, line_width_a, line_height_b, line_width_b;
  scanf("%d %d %d %d", &line_height_a, &line_width_a, &line_height_b, &line_width_b);
  if(line_height_a * line_width_a > line_height_b * line_width_b) {
    printf("%d\n", line_height_a * line_width_a);
  } else {
    printf("%d\n", line_height_b * line_width_b);
  }
  return 0;
}
