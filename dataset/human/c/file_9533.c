#include <stdio.h>
#include <stdlib.h>

int main(void){
  int N;
  int D, X;
  int *a;
  int choco_sum=0;
  int i, j;
  
  scanf("%d", &N);
  scanf("%d %d", &D, &X);
  a = malloc(N*(sizeof(int)));
  
  for(i=1;i<=N;i++){
    scanf("%d", &a[i-1]);
  }
  for(i=1;i<=N;i++){
    j=0;
    while(D>=j*a[i-1] + 1){
      choco_sum += 1;
      j++;
    }
  }
  printf("%d", X + choco_sum);

  free(a);
  return 0;
}
