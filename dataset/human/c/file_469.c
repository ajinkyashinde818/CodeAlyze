#include <stdio.h>
int main(void){
  int n,a[200000],i;
  long s=0,sn=0,ar,sa,min=2000000000;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
    s+=a[i];
  }
  for (i=0;i<n-1;i++){
    sn+=a[i];
    ar=s-sn;
    sa=(ar>sn)? ar-sn:sn-ar;
    if (min>sa) min=sa;
  }
  printf("%ld\n",min);
  return 0;
}
