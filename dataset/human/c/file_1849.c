#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))
int compare_int(const void *a, const void *b){
  return *(long int*)b - *(long int*)a; // 大きい順
}
// 公約数
long int gcd(long int a, long int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}
// 最小公倍数 = a * b / 最大公約数
// 公倍数
long int lcm(long int a, long int b){
  return a * b / gcd(a, b);
}


// min
int main(void){
  int n;
  int a[21];
  int b[21];
  int c[21];
  int ans = 0;
  
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &b[i]);
  }
  for(int i = 0; i < n-1; i++){
    scanf("%d", &c[i]);
  }

  for(int i = 0; i < n - 1; i++){
    ans += b[a[i] - 1];
    if(a[i] + 1 == a[i + 1]){
      ans += c[a[i] - 1];
    }
    //    printf("a[%d] = %d, ans = %d\n", i, a[i], ans);
  }
  ans += b[a[n-1] - 1];
  
  printf("%d\n", ans);
  return 0;
}
