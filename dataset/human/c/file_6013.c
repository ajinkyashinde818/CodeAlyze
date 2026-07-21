#include <stdio.h>

int main(){

  int r[200000];
  int n, i, j, max, min;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &r[i]);

  max = r[1] - r[0];
  min = r[0];

  for(j = 1; j < n; j++){
    if(r[j]-min > max)
      max = r[j] - min;
    if(r[j] < min)
      min = r[j];
  }


  printf("%d\n", max);

  return 0;
}
