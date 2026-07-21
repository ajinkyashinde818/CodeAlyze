#include<stdio.h>
int main(){
  int a, b, k, i, c[100], j = 0;
  scanf("%d %d %d", &a, &b, &k);
  for(i = 1; i <= 100; ++i){
    if(a % i == 0 && b % i == 0){
      c[j] = i;
      ++j;
    }
  }
  printf("%d\n", c[j - k]);
  return 0;
}
