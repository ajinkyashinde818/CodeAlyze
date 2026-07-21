#include <stdio.h>
int main(){
  int a[101],n,x,d,i;
  scanf("%d%d%d",&n,&d,&x);
  for(i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  x+=n;
  for(i=0;i<n;i++){
      x+=(d-1)/a[i];
  }
  printf("%d",x);
    return 0;
}
