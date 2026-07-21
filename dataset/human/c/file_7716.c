#include<stdio.h>
#include<stdlib.h>

int main(void){
  int i, size, count;
  int *x;

  count = 0;
  size = 10000;
  x = (int *)malloc(sizeof(int)*size);

  for(i=0;i<size;i++){
    x[i] = 0;
  }

  while(1){
    scanf("%d", &x[count]);
    if(x[count] == 0){
      break;
    }
    count++;
  }

  for(i=0;i<count;i++){
    printf("Case %d: %d\n", i+1, x[i]);
  }

  return 0;

}
