#include<stdio.h>
int main(){
  
  int k,n,i,max;
  scanf("%d %d",&k,&n);
  
  int a[n+1],b[n+1];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  b[0] = a[0] + (k - a[n-1]);
  for(i=1;i<n;i++){
    b[i] = a[i] - a[i-1];
    //printf("%d",
  }
  max = b[0];
  for(i=0;i<n;i++){
    if(max < b[i]) max = b[i];
  }
  
  printf("%d",k-max);
  
  return 0;
}
