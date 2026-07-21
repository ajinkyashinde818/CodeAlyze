#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  long long int number_n, i, min_abs_number = INT_MAX, sum = 0, counter_minus_number = 0;
  scanf("%lld", &number_n);
  long long int number_array[number_n];
  for(i = 0; i < number_n; i++) {
    scanf("%lld", &number_array[i]);
    if(number_array[i] < 0) {
      counter_minus_number++;
    }
    number_array[i] = abs(number_array[i]);
  }
  for(i = 0; i < number_n; i++) {
    if(number_array[i] < min_abs_number) {
      min_abs_number = number_array[i];
    }
    sum += number_array[i];
  }
  if(counter_minus_number % 2 == 1) {
    sum -= 2 * min_abs_number;
  }
  printf("%lld\n", sum);
  return 0;
}
