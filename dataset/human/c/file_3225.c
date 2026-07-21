#include <stdio.h>

int main(void){
  int k,n;
  scanf("%d %d",&k,&n);
  int a[n],b[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  b[0]=k+a[0]-a[n-1];
  int temp = b[0];
  for(int i=1;i<n;i++){
    b[i] = a[i]-a[i-1];
  }
  for(int i =0;i<n;i++){
    if (temp < b[i]){
      temp = b[i];
    }
  }
  printf("%d",k-temp);
  return 0;

}
