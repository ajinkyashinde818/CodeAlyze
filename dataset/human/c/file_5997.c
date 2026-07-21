#include<stdio.h>
#define N 200000

int main(){

  int i,n,maxv,minv;
  int arr[N];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  maxv = arr[1] - arr[0];
  minv = arr[0];
  
  for(i=1;i<n;i++){
    if(maxv<arr[i]-minv){  
    maxv = arr[i]-minv;
    }
    if(minv>arr[i]){
      minv = arr[i];
    }
  }
    
  printf("%d\n",maxv);

  return 0;
}
