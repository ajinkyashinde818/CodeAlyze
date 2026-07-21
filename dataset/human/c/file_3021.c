#include <stdio.h>

int main(){
  int k, n, distance;
  int max = 0, sum = 0;

  scanf("%d %d", &k, &n);
  int house[n] = {0};

  for(int i = 0; i < n; i++){
    scanf("%d", &distance);
    house[i] = distance;
    if(i != 0){
      sum += house[i] - house[i-1];
      if((house[i]-house[i-1])>max){
	max = house[i] - house[i-1];
      }
    }
  }

  sum += (k-house[n-1]+house[0]);
  if(max < (k-house[n-1]+house[0])) max = (k-house[n-1])+house[0];
    

  printf("%d\n", sum-max);
}
