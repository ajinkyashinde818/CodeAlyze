#include <stdio.h>

int main() {
  int number_of_buttons, i, current_button = 0, count = 0;
  scanf("%d", &number_of_buttons);
  int button[number_of_buttons];
  int button_flag[100000] = {};
  for(i = 0; i < number_of_buttons; i++) {
    scanf("%d", &button[i]);
  }
  for(i = 0; i < number_of_buttons; i++) {
    if(current_button == 1) {
      printf("%d\n", count);
      break;
    }
    if(button_flag[current_button] != 0) {
      printf("-1\n");
      break;
    }
    button_flag[current_button]++;
    current_button = button[current_button] - 1;
    count++;
  }
  return 0;
}
