#include<stdio.h>
int main(){
  int k,n,i,max;
  scanf("%d %d",&k,&n);
  int a[n];
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=1,max=a[1]-a[0];i<n-1;i++){
    if(max<a[i+1]-a[i])max=a[i+1]-a[i];
  }
  if(max<k-a[n-1]+a[0])max=k-a[n-1]+a[0];
  printf("%d",k-max);
  return 0;
}
