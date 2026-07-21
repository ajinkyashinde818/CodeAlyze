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

  long int n;
  int k;
  int h[100001];
  long int ans = 0;;

  scanf("%ld%d", &n, &k);
  
  for(long int i = 0; i < n; i++){
    scanf("%d", &h[i]);
    if(h[i] >= k){
      ans++;
    }
  }

  //  fprintf(stderr, "n / 2 = %f\n", 3.0/5.0);
  printf("%ld\n", ans);
  
  return 0;
}
