//ALDS1-1-D: Maximum Profit
//2019.05.24

#include <stdio.h>

int main(void){
  int n, t;
  int rt, rj;
  int min_present = 1000000000;
  int max_profit = -1000000000+1;

  scanf("%d\n", &n);
  scanf("%d\n", &rj);
  min_present = rj;
  for (t = 1; t < n; t++) {
    scanf("%d\n", &rt);
    if (rj < min_present) min_present = rj;
    if (max_profit < rt - min_present) max_profit = rt - min_present;
    rj = rt;
  }
  printf("%d\n", max_profit);

  return 0;
}
