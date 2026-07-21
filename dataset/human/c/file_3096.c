#include<stdio.h>
#include<stdlib.h>

int main(){
  int k,n;
  
  scanf("%d%d",&k,&n);
  int a[n];
  for(int i=0;i<n;i++){
  	scanf("%d",&a[i]);
    
  }
  int d;
  d=a[0]+k-a[n-1];
  
  for(int i=0;i<n-1;i++){
    if(d<a[i+1]-a[i]){
      d=a[i+1]-a[i];
    }
  }
  
  printf("%d",k-d);
  
  return 0;
}
