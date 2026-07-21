#include <stdio.h>

int main() {
  int red_ball, green_ball, blue_ball, number, count = 0, i, j, temp_red, temp_green;
  scanf("%d %d %d %d", &red_ball, &green_ball, &blue_ball, &number);
  for(i = 0; (i * red_ball) <= number; i++) {
    temp_red = i * red_ball;
    for(j = 0; (temp_red + (j * green_ball)) <= number; j++) {
      temp_green = j * green_ball;
      if((number - (temp_red + temp_green)) % blue_ball == 0) {
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
