#include <stdio.h>

int abs(int x){
  if(x<0){
    x*=-1;
  }
  return x;
}

int main(){
  int i,k,n,max=0;
  scanf("%d %d",&k,&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  a[n]=a[0]+k;
  for(i=0;i<n;i++){
    if(abs(a[i]-a[i+1])>=max){
      max=abs(a[i]-a[i+1]);
    }
  }
  printf("%d",k-max);
  return 0;
}
