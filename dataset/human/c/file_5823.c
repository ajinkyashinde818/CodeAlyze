#include <stdio.h>
int main(){
  int a[200000],n,i,j,r,min,max;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  min = a[0];
  max = a[1] - a[0];
  for(i=1;i<n;i++){
    if(max<a[i]-min) max = a[i] - min;
    if(a[i]<min) min = a[i];
  }
      printf("%d\n",max);
  return 0;
}
