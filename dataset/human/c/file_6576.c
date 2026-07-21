#include<stdio.h>
int main(void){
  int i,n;
  scanf("%d",&n);
  int r[n];
  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }
  int max=-2147483647;
  int min=r[0];
  for(i=1;i<n;i++){
    if(r[i]-min>max){
      max=r[i]-min;
    }
    if(r[i]<min){
      min=r[i];
    }
  }
  printf("%d\n",max);
  return 0;
}
