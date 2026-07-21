#include <stdio.h>
#include <stdlib.h>

int main(void){
  int N;
  int *a;
  int i;
  int k;
  scanf("%d",&N);
  a = (int *)malloc(N * sizeof(int));
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
    a[i]--;
  }
  k=a[0];
  if(k!=1){
    for(i=1;i<N;i++){
      k=a[k];
      if(k==1){
	printf("%d\n",i+1);
	return 0;
      }
    }
  }
  else {
    printf("1\n");
    return 0;
  }
  printf("-1\n");
  return 0;
}
