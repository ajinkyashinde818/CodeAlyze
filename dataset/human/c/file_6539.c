#include<stdio.h>
#include<stdlib.h>

int main(){
  int i = 0;
  int num = 0;
  int min = 0;
  int max = 0;
  int *data;

  while(1){
    scanf("%d",&num);
    if(num >= 2 && num <= 200000){
      break;
    }
  }

  data = (int *)malloc(sizeof(int)* num);

  for(i = 0;i < num;i++){
    while(1){
      scanf("%d",&data[i]);
      if(data[i] >= 1 && data[i] <= 1000000000){
        break;
      }
    }
  }

  min = data[0];
  max = data[1] -min;

  for(i = 1;i < num;i++){
    if(max < data[i] - min){
      max = data[i] -min;
    }
    if(min > data[i]){
      min = data[i];
    }
  }
  printf("%d",max);
  printf("\n");
  free(data);
  return 0;
}
