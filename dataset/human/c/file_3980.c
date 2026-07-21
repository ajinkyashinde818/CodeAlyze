#include <stdio.h>

int main(void){
  int A, B, K, i, count;

  scanf("%d %d %d", &A, &B, &K);
  count=0;
  int array[100];
  for(i=100;i>0;i--){
    if(A%i==0&&B%i==0){
      array[count]=i;
      count+=1;
    }
  }
  printf("%d\n", array[K-1]);
  return 0;
}
