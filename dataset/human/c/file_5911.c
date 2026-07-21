#include <stdio.h>

int main(){
  int x,a[200000],i,n,r=-1e9,r0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  x=a[0];

  for(i=1;i<n;i++){
    r0=a[i]-x;
    if(r<r0) r=r0;
    if(x>a[i]) x=a[i];
  }

  printf("%d\n",r);

  return 0;

}
