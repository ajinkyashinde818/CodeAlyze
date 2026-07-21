#include<stdio.h>

int main(){
  int n,num;
  int a[40];
  int b[40];
  int c[40];
  
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  for(int i=0;i<n-1;i++){
    scanf("%d",&c[i]);
  }
  
  for(int i=0;i<n;i++){
    num+=b[i];
    if(a[i+1]-a[i]==1){
      num+=c[a[i]-1];
    }
  }
  
  printf("%d",num);
  
  return 0;
}
