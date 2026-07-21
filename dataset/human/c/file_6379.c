#include <stdio.h>

int main(){
  int a[200200],i,maxr,minr,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  minr = a[0];
  maxr = a[1] - a[0];
  for(i=1;i<n;i++){
    if(maxr<=a[i]-minr) maxr = a[i] - minr;
    if(minr>=a[i]) minr = a[i];
  }
  printf("%d\n",maxr);
  return 0;
}
