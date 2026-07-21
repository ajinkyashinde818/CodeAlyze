#include<stdio.h>

int main(void){
  int n, R[200000], max, min;


  scanf("%d", &n);
  for(int i = 0; i< n; i++){
//    printf("loop 0\n");
    scanf("%d", &R[i]);
    if(i > 0){
        int d;
//        printf("%d - %d\n", R[i], min);
        d = R[i] - min;
        if(d > max || i == 1) max = d;
    }
    if(i == 0 || min > R[i]){
      min = R[i];
    }
  }

  printf("%d\n", max);


  return 0;
}
