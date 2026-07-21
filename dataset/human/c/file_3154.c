#include<stdio.h>
int main(void){
  int round, house, i,range;
  scanf("%d %d", &round, &house);
  int dist[house];
  for(i = 0; i < house; i++){
    scanf("%d", &dist[i]);
  }
  
  range = dist[1] - dist[0];
  
  for(i = 1; i < house - 1; i++){
    if(range < (dist[i+1] - dist[i])){
      range = dist[i+1] - dist[i];
    }
  }
 if(range < (round - dist[house-1] + dist[0])){
   range = round - dist[house-1] + dist[0];
 }
  
  round = round - range;
  printf("%d\n",round);
  
  return 0;
}
