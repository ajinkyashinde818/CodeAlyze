#include<stdio.h>
int main(void){
  int n,i,j,max,min,ans;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  max=a[1]-a[0];
  min=a[0];
  for(i=1;i<n;i++){
    ans=a[i]-min;
    if(max<ans){
      max=ans;
    }
    if(a[i]<min){
      min=a[i];
    }
  }
  printf("%d\n",max);
  return 0;
}
