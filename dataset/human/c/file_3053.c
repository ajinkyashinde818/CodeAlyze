#include<stdio.h>

int meter[200000];

int calculate(int circle, int house)
{ 
  int dis[200000];
  int max = 0;
  int i;

  for(i = 0; i < house; i++)
  {
    dis[i] = meter[i + 1] - meter[i];
    if((i + 1) == house)
      dis[i] = (circle - meter[i]) + meter[0];
    
    if(dis[i] > max)
      max = dis[i];
  }
  
  return max;
}

int main()
{
  int circle, house, i;
  int max = 0;
  int sum = 0;
  
  scanf("%d", &circle);
  scanf("%d", &house);
  
  for(i = 0; i < house; i++)
  {
    scanf("%d", &meter[i]);
  }
  
  max = calculate(circle, house);
  
  printf("%d\n", circle - max);
  
  return 0;
}
