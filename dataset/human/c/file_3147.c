#include<stdio.h>

int main(void){
  int k , n;
  scanf("%d %d",&k ,&n);

  int a[2*n];
  for(int i = 0;i < n;i ++){
    scanf("%d",&a[i]);
    a[n+i] = a[i] + k;
  }
  int min = k;
  for(int i = 0;i < n;i ++){
    if((a[n+i-1] - a[i]) <  min){
      min = a[n+i-1] - a[i];
    }
  }

  printf("%d\n",min);

  return 0;
}
