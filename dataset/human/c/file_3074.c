#include<stdio.h>
 
int main(void){
  int k,n,i;
  scanf("%d %d",&k,&n);
  int a[n];
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  
  int max = k-a[n-1] + a[0];
  for(i = 0;i < n-1;i++){
    if(a[i+1] - a[i] > max)
      max = a[i+1] -a[i];
  }

  printf("%d",k - max);
  return 0;
}
