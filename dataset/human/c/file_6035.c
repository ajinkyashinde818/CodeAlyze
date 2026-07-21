#include<stdio.h>
int main()
{
   int buy, sell, prof;
   int rate;
   int n;
   int i = 2;
   
   scanf("%d", &n);
   scanf("%d", &buy);
   scanf("%d", &sell);
   prof = sell - buy;
   if (prof < 0)
      buy = sell;
   while (i < n){
      scanf("%d", &rate);
      if (rate - buy > prof)
         prof = rate - buy;
      if (rate < buy)
         buy = rate;
      ++i;
   }
   printf("%d\n", prof);
   return 0;
}
