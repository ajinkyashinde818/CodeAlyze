#include <stdio.h>
int main(void) {

  int n;
  scanf("%d",&n);

  int i,a=-1000000000,b=1000000000;

  for(i=0; i<n; i++) {
    int x;
    scanf("%d",&x);
    if(i && x-b>a)
      a=x-b;
    if(b>x)
      b=x;
  }

  printf("%d\n",a);
  
  return 0;
}
