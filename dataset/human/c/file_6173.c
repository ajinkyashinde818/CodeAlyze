#include <stdio.h>
#include <math.h>

int main(void){

  int r[200000], i, j, n, co = 1000000001, coo = -1000000000;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &r[i]);
  }

  for(i = 0; i < n; i++){
    if(co < r[i]) continue;
    co = r[i];
    for(j = 1+i; j < n; j++){
      if(coo < r[j] - r[i]){
	coo = r[j] - r[i];
      }
    }
  }

  printf("%d\n", coo);

  return 0;
}
