#include <stdio.h>

int main(){
  int a,b,c,d;
  int cu_a, cu_b;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  cu_a = a*b;
  cu_b = c*d;

  int ans;
  if(cu_a >= cu_b){
    ans = cu_a;
  } else {
    ans = cu_b;
  }

  printf("%d", ans);
  return 0;
}
