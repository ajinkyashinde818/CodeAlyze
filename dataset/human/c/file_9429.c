#include <stdio.h>

int main() {
  int number_of_remaining_chocolates, number_n, i, j, number_of_dates, answer, temp;
  scanf("%d", &number_n);
  scanf("%d %d", &number_of_dates, &number_of_remaining_chocolates);
  answer = number_of_remaining_chocolates;
  for(i = 0; i < number_n; i++) {
    scanf("%d", &temp);
    for(j = 0; ; j++) {
      if(j * temp + 1 <= number_of_dates) {
        answer++;
      } else {
        break;
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}
