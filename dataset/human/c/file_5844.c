#include "stdio.h"

int main(void){
  int x,i;
  long a,b,max,min,gap;
  max = 0;
  min = 0;
  gap = -99999999999999;
  scanf("%d", &x);
  for(i = 0; i < x; i++){
    scanf("%ld", &a);
    if(i == 0){//初期化
      max = a;
      min = a;
    }else{
      if(a > max){
        max = a;//最大値更新
        b = max - min;
        if(b > gap){//差が今までより大きければ更新
          gap = b;
        }
      }else{
        b = a - max;
        max = a;
        if(a < min){
          min = a;
        }
        if(b > gap){
          gap = b;
        }
      }
    }
  }
  printf("%ld\n", gap);
}
