#include<stdio.h>
#define MAX 200000

int main(){
  int i,n,max,min;
  int data[MAX];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&data[i]);
  }

  min = data[0];
  max = data[1] - min;
  if(data[1] < min){
    min = data[1];
  }

  for(i = 2;i < n;i++){
    if(max < data[i]-min){
      max = data[i] - min;
    }
    if(data[i] < min){
      min = data[i];
    }
  }
  printf("%d\n",max);
}
