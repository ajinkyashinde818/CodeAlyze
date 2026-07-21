#include <stdio.h>

int main(void){
  int n,d,x,b=0;
  int a[105];
  scanf("%d", &n);
  scanf("%d %d", &d, &x);
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
    b+=(d-1)/a[i]+1;
  }

  
  printf("%d", b+x);
  return 0;
}
