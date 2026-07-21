#include <stdio.h>
int main(void) {
  int house_number;
  int cir_lake;
  int dis_house[200000];
  int dis[200000];
  int i, max;
  
  scanf("%d %d", &cir_lake, &house_number);
  for(i = 0; i < house_number; i++) {
    scanf("%d", &dis_house[i]);
  }
  for(i = 0; i < house_number - 1; i++) {
    dis[i] = dis_house[i + 1] - dis_house[i];
  }
  dis[house_number - 1] = cir_lake - dis_house[house_number - 1] + dis_house[0];
  max = dis[0];
  for(i = 0; i < house_number; i++) {
    if(max < dis[i]) {
      max = dis[i];
    }
  }
  printf("%d", cir_lake - max);
  return 0;
}
