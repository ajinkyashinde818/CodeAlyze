#include<stdio.h>
#define N 200000
int main(){
  int x,i,max=0,min,result,a[N];
  scanf("%d",&x);
  for(i=0;i<x;i++)
    scanf("%d",&a[i]);
  min=a[0];
  max=a[1]-a[0];
  for(i=1;i<x;i++){    
    if(a[i]-min>max)
      max=a[i]-min;
    if(a[i]<min)
      min=a[i];
    
  }
  printf("%d\n",max);
  return 0;
}
