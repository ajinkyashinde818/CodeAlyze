#include <stdio.h>  /*入出力*/
#include <stdlib.h> /*標準ライブラリ*/
#include <string.h> /*文字列*/
#include <math.h>   /*計算*/
#include <assert.h> /*確認*/
#include <ctype.h>  /*文字操作*/
#include <stdbool.h>/*bool型*/
#include <limits.h> /*限界*/

#define rep(i, n) for(int  i = 0; i < (n); i++)
#define max(a,b) ((a>b)?a:b)
#define ABS(a) (((a)>(0))?a:-(a))
#define LL long long
#define MOD 1000000007//10^9+7(素数)

//abc 160 C

int main(void)
{
  long N;
  long K;
  long save;
  long ans = 0;
  long count[200000];
  scanf("%ld %ld", &K, &N);
  for (long i = 0; i < N; i++) {
    scanf("%ld", &count[i]);
  }
  save = count[0];
  for (long i = 0; i < N; i++) {
    if (i != N-1) {
      count[i] = count[i+1]-count[i];
    }else{
      count[i]= K - count[i] + save;
    }
  }
  for (long i = 0; i < N; i++) {
    if (count[i] > ans) {
      ans = count[i];
    }
  }
  printf("%ld\n",K - ans );
  return 0;
}
