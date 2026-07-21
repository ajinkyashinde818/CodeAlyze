#include <stdio.h>
#define N 200000

int main(){

  int i, j, n, min, max;
  int num[N];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &num[i]);
  }

  min = num[0];
  max = num[1]-num[0];
  for(j=1; j<n; j++){
    if(max < num[j]-min){
      max = num[j]-min;
    }
    if(min > num[j]){
      min = num[j];
    }
  }

  printf("%d\n", max);

  return 0;
}
