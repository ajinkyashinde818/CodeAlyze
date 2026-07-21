#include<stdio.h>

void dfs(int, int *);

int n, m, x;
int A[10000][10000];
int minPrice = -1;

int main()
{
  scanf("%d %d %d", &n, &m, &x);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) { // 0番目の要素はC(値段)なので、(m + 1)回
      scanf("%d", &A[i][j]);
    }
  }
  int sums[m + 1];
  for (int i = 0; i <= m; i++) {
    sums[i] = 0;
  }
  dfs(0, sums);
  printf("%d\n", minPrice);
  return 0;
}

void dfs(int i, int *sums) {
  // 全てのアルゴリズムの理解度がX以上になっているか判定する
  int satisfied = 1;
  for (int j = 1; j <= m; j++) { // 0番目はCであることとm番目に値が入っていることに注意
    if (sums[j] < x) {
      satisfied = 0;
      break;
    }
  }
  
  if (satisfied == 1) {
    if (minPrice == -1) {
      // 初めて満たした
      minPrice = sums[0];
    } else if (sums[0] < minPrice) {
      // 小さくなる場合のみ更新
      minPrice = sums[0];
    }
  }
  
  if (i > n) {
    // 末尾まで調べ終わっている
    return;
  }
  
  // i番目を使用しない場合について調べる
  dfs(i + 1, sums);
  if (satisfied == 1) {
    // 既に満たしている場合、i番目を使用する場合については調べない
    return;
  }
  
  // i番目を使用する場合について調べる
  int sumsCpy[m + 1];
  for (int j = 0; j <= m; j++) {
    sumsCpy[j] = sums[j] + A[i][j];
  }
  dfs(i + 1, sumsCpy);
}
