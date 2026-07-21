#include <stdio.h>

int main(){
  int n,count=0;
  scanf("%d",&n);
  int a[n],b[n],c[n-1];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
  }
  
  for(int i=0;i<n-1;i++){
    if(a[i+1]-a[i]==1){
      count+=b[a[i]-1]+c[a[i]-1];
    } else{
       count+=b[a[i]-1];
    }
  }
  count+=b[a[n-1]-1];
  printf("%d",count); 
}
