#include<stdio.h>
#include<stdlib.h>
int main(void){
  int i,*arr,num,min,max;
  scanf("%d",&num);
  arr = (int*)malloc(sizeof(int)*num);
  for(i=0;i<num;i++) scanf("%d",&arr[i]);
  max = arr[1]-arr[0];
  min = arr[0];
  for(i=1;i<num;i++){
    if(arr[i]-min > max) max = arr[i]-min;
    if(min > arr[i]) min = arr[i];
  }
  
  printf("%d\n",max);
  return 0;
}
