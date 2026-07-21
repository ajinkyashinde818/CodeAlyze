#include <stdio.h>

int main(){
  int n,r,i,minp,maxp;

  scanf("%d",&n);
  scanf("%d",&r);

  minp=r;
  maxp=0-r;
  for(i=1;i<n;i++){
    scanf("%d",&r);
    if(maxp<r-minp)maxp=r-minp;
    if(minp>r)minp=r;
  }

  printf("%d\n",maxp);

  return 0;
}
