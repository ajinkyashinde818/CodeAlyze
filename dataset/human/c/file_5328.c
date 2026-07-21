/* C - Skill Up */

#include <stdio.h>
// #define INF (int)1e9
const int INF = 1e9;

int main(void){
  int N, M, X, ans = INF;
  scanf("%d %d %d", &N, &M, &X);
  int C[N], A[N][M];
  for(int i = 0; i < N; i++){
    scanf("%d", &C[i]);
    for(int j = 0; j < M; j++){
      scanf("%d", &A[i][j]);
    }
  }
  /* bit全探索 */
  for(int bit = 0; bit < (1 << N); bit++){
    int money = 0, totalA[M]; // 可変長配列は = {} で初期化できない
    // 以下のように配列を初期化
    for(int j = 0; j < M; j++){
      totalA[j] = 0;
    }
    for(int i = 0; i < N; i++){
      if(bit & (1 << i)){
        money += C[i];
        for(int j = 0; j < M; j++){
          totalA[j] += A[i][j];
        }
      }
    }
    int judge = 1;
    for(int j = 0; j < M; j++){
      if(totalA[j] < X){
        judge = 0;
        break;
      }
    }
    if(judge && money < ans){
      ans = money;
    }
  }
  if(ans == INF){
    puts("-1");
  }else{
    printf("%d\n", ans);
  }
  return 0;
}
