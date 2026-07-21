#include <stdio.h>

int main() {
  int number_n, number_m, i, j = 0;
  scanf("%d %d", &number_n, &number_m);
  long long int stage[number_n+1];
  int broken_stage[number_m];
  for(i = 0; i < number_m; i++) scanf("%d", &broken_stage[i]);
  stage[0] = 1;
  stage[1] = (broken_stage[0] == 1)? 0 : 1;
  for(i = 2; i <= number_n; i++) {
    stage[i] = stage[i-1] + stage[i-2];
    for(; j < number_m; j++) {
      if(broken_stage[j] == i) {
        stage[i] = 0;
        break;
      } else if(broken_stage[j] > i) {
        break;
      }
    }
    if(stage[i] > 1000000007) stage[i] -= 1000000007;
  }
  printf("%lld\n", stage[number_n]);
  return 0;
}
