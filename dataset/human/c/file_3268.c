#include <stdio.h>
int main(void){
  int k,n,i,d,x;
  int a[200000];
  
  scanf("%d%d",&k,&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  d=a[0]+k-a[n-1];
  for(i=0;i+1<n;i++){
    if(d<a[i+1]-a[i])
      d=a[i+1]-a[i];
  }
  x=k-d;
  printf("%d",x);
  return 0;
}
