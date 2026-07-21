#include <stdio.h>

int main(void)
{
    int timeCount, count, minPrice, difference, priceOnTime;
    int benefit = -999999999;
    char tempString[12];
    fgets(tempString,sizeof(tempString),stdin);
    sscanf(tempString,"%d",&timeCount);

    fgets(tempString,sizeof(tempString),stdin);
    sscanf(tempString,"%d",&priceOnTime);
    minPrice = priceOnTime;

    for (count = 0; count < timeCount - 1; count++) {
      fgets(tempString,sizeof(tempString),stdin);
      sscanf(tempString,"%d",&priceOnTime);
      difference = priceOnTime - minPrice;
      if (benefit < difference) {
          benefit = difference;
      }

      if(priceOnTime < minPrice) {
          minPrice = priceOnTime;
      }
    }

    printf("%d\n",benefit);

    return 0;
}
