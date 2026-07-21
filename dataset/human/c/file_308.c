#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  int min = 1000000000;
  int neg_num = 0;
  long long int ans = 0;
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d", &a);
    if (a < 0){
      neg_num++;
      a = (-1) * a;
    }
    ans += a;
    if(min > a){
      min = a;
    }
  }
  if (neg_num % 2 == 1){
    ans -= 2 * min;
  }
  printf("%lld\n", ans);
  return 0;
}
