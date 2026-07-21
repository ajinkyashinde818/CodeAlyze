#include <stdio.h>

int main(void){
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int max=a[1]-a[0];
  int minv=a[0];
  for(i=1;i<n;i++){
    if(max<a[i]-minv) max=a[i]-minv;
    if(minv>a[i]) minv=a[i];
  }
  printf("%d\n",max);
  return 0;
}
