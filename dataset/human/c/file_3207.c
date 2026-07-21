#include <stdio.h>

int main (void)
{
  int lake;
  int home;
  int i;
  int distance=0;
  
  scanf("%d", &lake);
  scanf("%d", &home);
  
  int house[home];
  int walk[home];
  int max_walk=0, max;
  
  for (i=0; i<home; i++)
    scanf("%d", &house[i]);
  
  for (i=0; i<home - 1; i++) {
    walk[i] = house[i+1] - house[i];
    
    if (walk[i] > max_walk) {
      max_walk = walk[i];
      max = i;
    }
  }
  
  walk[home - 1] = house[0] + (lake - house[home - 1]);
  if (walk[home - 1] > max_walk) {
    max_walk = walk[home-1];
    max = home-1;
  }
  
  for (i=0; i<max; i++)
    distance += walk[i];
  
  for (i=max+1; i<home; i++)
    distance += walk[i];
  
  printf("%d\n",distance);
  
  return 0;
}
