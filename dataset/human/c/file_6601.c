#include <stdio.h>

int main()
{
  int count, price, min, profit;
  scanf("%d", &count);

  int prices[count - 1];

  for (int n = 0; n < count; ++n)
  {
    scanf("%d", &prices[n]);
  }

  min = prices[0];
  profit = prices[1] - prices[0];

  for (int j = 1; j < count; ++j)
  {
    if (prices[j] < min)
      min = prices[j];
    else if (prices[j] - min > profit)
      profit = prices[j] - min;
  }

  printf("%d\n", profit);

  return 0;
}
