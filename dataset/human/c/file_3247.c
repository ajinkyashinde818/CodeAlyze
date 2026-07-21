#include <stdio.h>
int main(){
  int K,n,l,min;
  scanf("%d %d",&K,&n);
  int a[n*2];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++){
    a[n+i]=a[i]+K;
  }
  l=K;
  for(int i=0;i<n;i++){
    min=a[n-1+i]-a[i];
    if(min<l){
      l=min;
    }
  }
  printf("%d",l);
  return 0;
}
