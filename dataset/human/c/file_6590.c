#include <stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  int R[n];

  for ( int i = 0; i < n; i++ ) scanf("%d", &R[i]);

  int maxv = -2000000000; //十分小さい値を初期値に設定
  int minv = R[0];
  
  for ( int i = 1; i < n; i++ ) { //ここで毎回R[i]を読み込めば、配列は不要
    maxv = maxv < (R[i] - minv) ?  R[i] - minv : maxv; //最大値を更新
    minv = minv > R[i] ? R[i] : minv;        //ここまでの最小値を保持しておく
  }
  
  printf("%d\n", maxv);
  return 0;
}
