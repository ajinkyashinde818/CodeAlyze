#include<stdio.h>

int main(){
  int j,i,n,min,max;
  int a[200000];
  
  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]); //配列に入力

  min = a[0]; 
  max = a[1] - min;
  
  for(j=1;j<n;j++){ // 利益の算出
    if(a[j-1]<min)
      min = a[j-1];
    if(max < a[j] - min)
      max = a[j] - min;
  }
  
  printf("%d\n",max);

  

  return 0;
}
